#include<stdio.h>
#include<string.h>
struct dog{
	char name[10];
	char breed[10];
	int age;
	char color[10];
};

int main()
{
	struct dog my_dog = {"tyke", "bulldog", 5, "white"};
	struct dog *ptr_dog;
	ptr_dog = &my_dog;


	printf("Dog's name: %s\n", ptr_dog->name);
	printf("Dog's breed: %s\n", ptr_dog->breed);
	printf("Dog's age: %d\n", ptr_dog->age);
	printf("Dog's color: %s\n", ptr_dog->color);

	// changing the name of dog from tyke to jack
	strcpy(ptr_dog->name, "jack");
	// increasing age of dog by 1 year
	ptr_dog->age++;
	
	printf("Dog's new name is: %s\n", ptr_dog->name);
	printf("Dog's age is: %d\n", ptr_dog->age);
	
	return 0;
}
/*How it works ?

In lines 3-8, we have declared a structure of type dog which has four members namely name, breed, age and color.

In line 12, a variable called my_dog of type struct dog is declared and initialized.

In line 13, a pointer variable ptr_dog of type struct dog is declared.

In line 14, the address of my_dog is assigned to ptr_dog using & operator.

In lines 17-20, the printf() statements prints the details of the dog.

In line 23, a new name is assigned to ptr_dog using the strcpy() function, because we can't assign a string value directly to ptr_dog->name using assignment operator.

In line 25, the value of ptr_dog->age is incremented by 1 using postfix increment operator. Recall that postfix ++ operator and -> have the same precedence and associates from left to right. But since postfix ++ is used in the expression first the value of ptr_dog->age is used in the expression then it's value is incremented by 1.*/
