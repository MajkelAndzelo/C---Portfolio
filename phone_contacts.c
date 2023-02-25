#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define MAX_SIZE 100

struct Person {
  char firstName[MAX_SIZE];
  char lastName[MAX_SIZE];
  char address[MAX_SIZE];
  char phoneNumber[MAX_SIZE];
};

struct PersonList {
  struct Person * persons;
  int count;
};

// funkcja wyświetlająca menu główne
void displayMainMenu() {
    printf("\n=== Personal data management application ===\n");
    printf("1. Add contact\n");
    printf("2. Display all contacts\n");
    printf("3. Edit contact\n");
    printf("4. Delete contact\n");
    printf("5. Sort by first name\n");
    printf("6. Sort by last name\n");
    printf("7. Exit\n");
    printf("Choose an option (1-6): ");
}

// funkcja dodająca nową osobę do listy
void addPerson(struct PersonList * list) {
  struct Person person;
    printf("\nEnter first name: ");
    scanf("%s", person.firstName);
    printf("Enter last name: ");
    scanf("%s", person.lastName);
    printf("Enter address: ");
    scanf("%s", person.address);
    printf("Enter phone number: ");
    scanf("%s", person.phoneNumber);
    list -> persons = realloc(list -> persons, sizeof(struct Person) * (list -> count + 1));
    list -> persons[list -> count] = person;
    list -> count++;
    printf("\nContact added to the list.\n");
}

// funkcja wyświetlająca dane osoby
void displayPerson(struct Person person) {
    printf("First name: %s\n", person.firstName);
    printf("Last name: %s\n", person.lastName);
    printf("Address: %s\n", person.address);
    printf("Phone number: %s\n", person.phoneNumber);
}

// funkcja wyświetlająca wszystkie osoby na liście
void displayAllPersons(struct PersonList list) {
  if (list.count == 0) {
    printf("\nNo contacts on the list.\n");
  } else {
    printf("\nContact list:\n");
    for (int i = 0; i < list.count; i++) {
      printf("============\nPerson %d:\n", i + 1);
      displayPerson(list.persons[i]);
      printf("============\n");
    }
  }
}

// funkcja wyszukująca osoby na liście
void searchPerson(struct PersonList list) {
  char query[MAX_SIZE];
  printf("\nEnter the first name or last name of the person you want to search for: ");
  scanf("%s", query);
  int count = 0;
  for (int i = 0; i < list.count; i++) {
    if (strcmp(query, list.persons[i].firstName) == 0 || strcmp(query, list.persons[i].lastName) == 0) {
      count++;
      printf("\nOsoba %d:\n", count);
      displayPerson(list.persons[i]);
    }
  }
  if (count == 0) {
    printf("\nNo person found with the given first name or last name.\n");
  }
}

// funkcja edytująca dane osoby na
void editPerson(struct PersonList * list) {
  int index;
  printf("\nEnter the number of the person whose data you want to edit (1-%d): ", list -> count);
scanf("%d", & index);
if (index < 1 || index > list -> count) {
printf("\nInvalid person number.\n");
} else {
struct Person * person = & (list -> persons[index - 1]);
printf("\nCurrent person data:\n");
displayPerson( * person);
printf("\nEnter new person data:\n");
printf("Enter first name: ");
scanf("%s", person -> firstName);
printf("Enter last name: ");
scanf("%s", person -> lastName);
printf("Enter address: ");
scanf("%s", person -> address);
printf("Enter phone number: ");
scanf("%s", person -> phoneNumber);
printf("\nPerson data has been updated.\n");
  }
}

// funkcja usuwająca osobę z listy
void deletePerson(struct PersonList * list) {
  int index;
    printf("\nEnter the number of the person you want to delete (1-%d): ", list -> count);
    scanf("%d", & index);
    if (index < 1 || index > list -> count) {
    printf("\nInvalid person number.\n");
  } else {
    for (int i = index - 1; i < list -> count - 1; i++) {
      list -> persons[i] = list -> persons[i + 1];
    }
    list -> count--;
    list -> persons = realloc(list -> persons, sizeof(struct Person) * list -> count);
    printf("\nThe person has been removed from the list.\n");
  }
}

// funkcja sortująca osoby na liście według imienia
void sortByFirstName(struct PersonList * list) {
  for (int i = 0; i < list -> count - 1; i++) {
    for (int j = i + 1; j < list -> count; j++) {
      if (strcmp(list -> persons[i].firstName, list -> persons[j].firstName) > 0) {
        struct Person temp = list -> persons[i];
        list -> persons[i] = list -> persons[j];
        list -> persons[j] = temp;
      }
    }
  }
    printf("\nThe list of people sorted by first name.\n");
}

// funkcja sortująca osoby na liście według nazwiska
void sortByLastName(struct PersonList * list) {
  for (int i = 0; i < list -> count - 1; i++) {
    for (int j = i + 1; j < list -> count; j++) {
      if (strcmp(list -> persons[i].lastName, list -> persons[j].lastName) > 0) {
        struct Person temp = list -> persons[i];
        list -> persons[i] = list -> persons[j];
        list -> persons[j] = temp;
      }
    }
  }
    printf("\nThe list of people sorted by last name.\n");
}

int main() {
  struct PersonList list;
  list.count = 0;
  list.persons = NULL;
  int choice;
  do {
    displayMainMenu();
    scanf("%d", & choice);
    switch (choice) {
    case 1:
      addPerson( & list);
      break;
    case 2:
      displayAllPersons(list);
      break;
    case 3:
      editPerson( & list);
      break;
    case 4:
      deletePerson( & list);
      break;
    case 5:
      sortByFirstName( & list);
      break;
    case 6:
      sortByLastName( & list);
      break;
    case 7:
      printf("\nGood Bye!\n");
    }
  } while (choice != 7);
  return 0;
}
