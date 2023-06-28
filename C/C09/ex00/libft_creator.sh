for file_c in ./src/*.c; 
    do
        file=$(basename "$file_c")
        filename="${file%.*}"
        gcc -Wall -Wextra -Werror -c ./src/$filename.c -o ./obj/$filename.o
    done

ar rc libft.a ./obj/*.o

