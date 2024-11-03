#include <stdio.h>
#include <stdlib.h>
int n, i;

typedef struct {
	int id;
	char name[50];
	float gpa;
} student ;

void data(student ptr[], int n){
	for(i=0;i<n;i++){
		printf("enter the ID for student %d : ",i+1);
		scanf("%d", &ptr[i].id);
		getchar();
		printf("enter the name of student %d : ",i+1);
		scanf("%[^\n]",ptr[i].name);
		getchar();
		printf("enter the GPA for student %d : ",i+1);
		scanf("%f",&ptr[i].gpa);
	}}
void show(student ptr[],int n){
	printf("\n \n student records : \n");
	for(i=0 ;i<n;i++){
		printf("ID: %d, NAME: %s, GPA: %.2f \n",ptr[i].id,ptr[i].name,ptr[i].gpa);
	}}






int main() {
	printf("Enter the number of studets: ");
	scanf("%d",&n);

	student *ptr = (student*)malloc(n*sizeof(student));
	data(ptr,n);
	show(ptr,n);
	return 0;
}
