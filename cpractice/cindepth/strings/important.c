#include <stdio.h>

int main()
{
	char str[] = "Mumbai";
       	/* char str[7];
	str = "Mumbai"	initialization has to be done in same statement like above for arrays because array name always point to the same storage */

	char *ptr = "Chennai";
	/* char *ptr;
        ptr = "Chennai"; this is valid because ptr is pointer variable can be assigned to any type of string or memory location */
	int i;
	char *temp;
	temp = str;
	for(i = 0; temp[i] != '\0'; i++) {
		printf("Character:%c\taddress:%p\n", temp[i], &temp[i]);
	}
	
	temp = ptr;
	for(i = 0; temp[i] != '\0'; i++) {
		printf("Character:%c\taddress:%p\n", temp[i], &temp[i]);
	}
	
	/* the following are invalid statements on strings */
	//str++;	// lvalue required error because array name always points to same storage
	//ptr[0] = 'B';	// segmentation fault because string constant can't be modified
	//scanf("d", ptr);// illegal due to pointer point garbage location
	//gets(ptr);	// segmentation fault
	//strcpy(ptr, "Bareily");	// segmentation fault

	return 0;
}
