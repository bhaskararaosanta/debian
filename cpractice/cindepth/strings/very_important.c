#include <stdio.h>

int main()
{
	char str[] = "Great";
	printf("%s\n", str);
	char *ptr = "Bhaskar";
	printf("%s\n", ptr);

	printf("Enter new string to str char array:");
	scanf("%s", str);
	printf("%s\n", str);
	//scanf("%s", ptr);
	/* segmentation fault because ptr pointed to string constant 
	 * and which we are trying to modify using scanf and it is illegal */ 
	
	//str = "linux";
	/* It is not possible to assign string constant to char array because
	 * array already point to constant memory which can't be modified. */
	ptr = "Learn";
	printf("%s\n", ptr);

	str[0] = 'B';
	printf("%s\n", str);
	//*ptr = 'G'; // segmentation fault because trying to modify string constant



	printf("%s\n", ("Embedded"+4));

	printf("Embedded\n"+4); 
	/* here Embedded act as pointer to the string "Embedded" and adding 4 
	 * it will move to the  4 four positions ahead. */


	/*****************  two-D arrays  and array of strings  ***********/
	
	char arr[3][20] = {
				"ABCDEF",
				"GHIJKLMNOP",
				"WXYZ"
			};
	printf("size of arr:%d\n", sizeof(arr));
	int i, j;
	printf("0th string:%s\n", arr[0]);
	printf("1st string:%s\n", arr[1]);
	printf("2nd string:%s\n", arr[2]);
	//arr[0] = "PQRST";
	/* It is not possible to assign string constant to char array because
	 * array already point to constant memory which can't be modified. */

	char *ptrarr[3] = {
				"ABCDEF",
				"GHIJKLMNOP",
				"WXYZ"
			};
	printf("size of ptrarr:%d\n", sizeof(ptrarr));
	printf("0th string:%s\n", ptrarr[0]);
	printf("1st string:%s\n", ptrarr[1]);
	printf("2nd string:%s\n", ptrarr[2]);
	ptrarr[0] = "RSTUV";
	printf("0th string:%s\n", ptrarr[0]);


	return 0;
}
