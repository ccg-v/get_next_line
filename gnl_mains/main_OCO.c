int main(int argc, char **argv)
{
    int     fd;
    char    *line;
    char    *temp;
    int     i;

    i = 0;
    temp = "";
    if (argc == 1)
        write (1, "No file specified!\n", 19);
    else if (argc > 2)
        write (1, "Too many arguments!\n", 20);
    else
    {
        fd = open(argv[1], O_RDONLY);
        line = "";
        // print two lines
        line = get_next_line(fd);
        printf("%s", line);
        line = get_next_line(fd);
        printf("%s", line);
         close (fd);
        while (temp != NULL)
        {
            temp = get_next_line(fd);
            free(temp);
        }
        temp = get_next_line(fd);
        printf("%s", temp);
        // close the file and free memory
        free(line);
        printf("----------\n");
        // open same file and print until EOF
        fd = open(argv[1], O_RDONLY);
        line = "";
        while (line != NULL)
        {
            line = get_next_line(fd);
            printf("%s", line);
        }
        fd = close(fd);
        return (0);
    }
}