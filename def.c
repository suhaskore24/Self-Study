#include <stdio.h>
#include <stddef.h>

#define SAFE_SUCCESS 0
#define SAFE_ERROR_NULL_POINTER -1
#define SAFE_ERROR_INVALID_SIZE -2
#define SAFE_ERROR_OVERFLOW -3

int safe_strcpy(char *dest, size_t dest_size, const char *src)
{
    
    if (dest == NULL || src == NULL)
    {
        return SAFE_ERROR_NULL_POINTER;
    }

    if (dest_size == 0)
    {
        return SAFE_ERROR_INVALID_SIZE;
    }

    size_t i = 0;

   
    while (src[i] != '\0')
    {
       
        if (i >= dest_size - 1)
        {
            dest[dest_size - 1] = '\0'; 
            return SAFE_ERROR_OVERFLOW;
        }

        dest[i] = src[i];
        i++;
    }

    
    dest[i] = '\0';

    return SAFE_SUCCESS;
}


int main()
{
    char buffer[10];
    int result = safe_strcpy(buffer, sizeof(buffer), "HelloWorld!");

    if (result == 0)
        printf("Copied string: %s\n", buffer);
    else
        printf("Error occurred: %d\n", result);

    return 0;
}
