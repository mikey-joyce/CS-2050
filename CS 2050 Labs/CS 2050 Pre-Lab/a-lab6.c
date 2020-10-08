#include<stdio.h>
#include<stdlib.h>

typedef struct{
	int ID, jobType;
	float salary;
}Employee;

//function prototypes
Employee *readEmployeeInfo(FILE *fp, int *numElems);
Employee *getEmployeeByID(Employee *, int numEmps, int id);
void setID(Employee *p, int id);
int getID(Employee *p);
void setSalary(Employee *p, float Salary);

void setSalary(Employee *p, float Salary){
	p->salary=Salary;
}

int getID(Employee *p){
	return p->ID;
}

void setID(Employee *p, int id){
	p->ID=id;
}

Employee *getEmployeeByID(Employee *p, int numEmps, int id){
	int i=0;
	for(i=0; i<numEmps; i++){
		if((p+i)->ID==id){
			return (p+i);
		}
	}
	printf("Person does not exist!\n");
	return NULL;
}

Employee *readEmployeeInfo(FILE *fp, int *numElems){
	if((fp=fopen("employee.txt", "r"))){
		//File properly opened
		printf("File open success!\n");
		
		*numElems=0;
		fscanf(fp, "%d", numElems);
		Employee *emps;
			
		emps=malloc((*numElems)*sizeof(Employee));
		if(emps==NULL){
			printf("Malloc failed!\n");
			return NULL;
		}
		
		for(int i=0; i<*numElems; i++){
			fscanf(fp, "%d,%d,%f", &(emps[i].ID), &(emps[i].jobType), &(emps[i].salary));
		}
		
		return emps;
	}
	printf("File open failure!\n");
	return NULL;
}

int main(void){
	FILE *fp=NULL;
	int length=0;
	Employee *emps;

	emps=readEmployeeInfo(fp, &length);
	
	//tests array of structs
	for(int i=0; i<length; i++){
		printf("Employee #%d: Pay: %f Position: %d\n", emps[i].ID, emps[i].salary, emps[i].jobType);
	}

	//tests getID
	Employee *test = getEmployeeByID(emps, length, emps[2].ID);

	printf("Test person's info: Pay: %f Position: %d\n", test->salary, test->jobType);
	
	//Changes their ID
	setID(test, 123128);
	setSalary(test, 5.12);
	printf("Test person's new info: ID: %d Pay: %f Position: %d\n", getID(test), test->salary, test->jobType);

	fclose(fp);
	free(emps);
}
