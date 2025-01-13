#include "main.h"

extern char **environ;      /* Declaración de la variable global con las variables de entorno */

/**
 * execute - Executes a command with arguments.
 * @args: Array of arguments, including the command.
 */
void execute(char **args)
{
    pid_t pid;              /* ID del proceso hijo */
    int status;             /* Estado del proceso hijo */
    char *cmd_path = NULL;  /* Ruta completa del comando a ejecutar */

    /* Built-in: env */
    if (strcmp(args[0], "env") == 0) /* Verifica si el comando es 'env' */
    {
        int i;
		for (i = 0; environ[i]; i++)
            printf("%s\n", environ[i]);
        return;
    }

    /* Built-in: exit */
    if (strcmp(args[0], "exit") == 0) /* Verifica si el comando es 'exit' */
    {
        free(args);      /* Libera la memoria asignada a args */
        exit(0);         /* Termina el programa con código de salida 0 */
    }

    /* Manejo de comandos con rutas absolutas o relativas */
    if (strchr(args[0], '/')) /* Verifica si el comando contiene '/' */
    {
        if (access(args[0], X_OK) == 0)         /* Verifica si el comando es ejecutable */
            cmd_path = strdup(args[0]);         /* Duplica la ruta para usarla más adelante */
        else
        {
            fprintf(stderr, "./shell: %s: No such file or directory\n", args[0]);
            return; /* Imprime un error si el archivo no existe o no es accesible */
        }
    }
    else
    {
        /* Buscar el comando en PATH */
        cmd_path = find_in_path(args[0]); /* Busca el comando en las rutas definidas en PATH */
        if (!cmd_path) /* Si el comando no se encuentra, muestra un mensaje de error */
        {
            fprintf(stderr, "./shell: %s: command not found\n", args[0]);
            return;
        }
    }

    /* Crear un proceso hijo para ejecutar el comando */
    pid = fork(); /* Crea un nuevo proceso */
    if (pid == -1) /* Si ocurre un error al crear el proceso hijo */
    {
        perror("fork");  /* Muestra un mensaje de error */
        exit(EXIT_FAILURE); /* Termina el programa */
    }

    if (pid == 0) /* Proceso hijo */
    {
        if (execve(cmd_path, args, environ) == -1) /* Ejecuta el comando en el proceso hijo */
        {
            perror(args[0]); /* Si execve falla, imprime un mensaje de error */
            exit(EXIT_FAILURE); /* Termina el proceso hijo con un error */
        }
    }
    else /* Proceso padre */
    {
        wait(&status); /* Espera a que el proceso hijo termine */
    }

    free(cmd_path); /* Libera la memoria asignada a cmd_path */
}

