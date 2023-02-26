#include <stdio.h>

#include <stdlib.h>

#include <string.h>

// Define a struct to represent a task
struct Task {
  char description[50];
  int priority;
};

// Initialize an empty array to store tasks
struct Task tasks[10];
int num_tasks = 0;

// Define a function to create a task
void create_task() {
  printf("Enter task description:\n");
  fgets(tasks[num_tasks].description, 50, stdin);

  int priority;
  while (1) {
    printf("Enter task priority (1-5):\n");
    scanf("%d", & priority);
    getchar(); // consume the newline character
    if (priority >= 1 && priority <= 5) {
      tasks[num_tasks].priority = priority;
      num_tasks++;
      printf("Task created successfully.\n");
      break;
    }
    printf("Invalid priority. Please enter a number between 1 and 5.\n");
  }
}

// Define a function to delete a task
void delete_task() {
  int index;
  printf("Enter task index to delete:\n");
  scanf("%d", & index);
  getchar(); // consume the newline character
  if (index >= 1 && index <= num_tasks) {
    for (int i = index - 1; i < num_tasks - 1; i++) {
      tasks[i] = tasks[i + 1];
    }
    num_tasks--;
    printf("Task deleted successfully.\n");
  } else {
    printf("Invalid index. Please enter a number between 1 and %d.\n", num_tasks);
  }
}

// Define a function to sort tasks by priority
void sort_tasks() {
  struct Task temp;
  for (int i = 0; i < num_tasks - 1; i++) {
    for (int j = i + 1; j < num_tasks; j++) {
      if (tasks[i].priority < tasks[j].priority) {
        temp = tasks[i];
        tasks[i] = tasks[j];
        tasks[j] = temp;
      }
    }
  }
  printf("Sorted tasks by priority:\n");
  for (int i = 0; i < num_tasks; i++) {
    printf("%d. %s (priority: %d)\n", i + 1, tasks[i].description, tasks[i].priority);
  }
}

// Define a function to show all tasks
void show_tasks() {
  printf("All tasks:\n");
  for (int i = 0; i < num_tasks; i++) {
    printf("%d. %s (priority: %d)\n", i + 1, tasks[i].description, tasks[i].priority);
  }
}

// Define a function to display the menu and get user's choice
int display_menu() {
  printf("\nTODO List Menu:\n");
  printf("1. Create a task\n");
  printf("2. Delete a task\n");
  printf("3. Sort tasks by priority\n");
  printf("4. Show all tasks\n");
  printf("5. Quit\n");
  printf("\nEnter your choice (1-5):\n");

  int choice;
  scanf("%d", & choice);
  getchar(); // consume the newline character

  return choice;
}

int main() {
  int choice;
  do {
    choice = display_menu();
    switch (choice) {
    case 1:
      create_task();
      break;
    case 2:
      delete_task();
      break;
    case 3:
      sort_tasks();
      break;
    case 4:
      show_tasks();
      break;
    case 5:
      printf("Goodbye!\n");
      break;
    default:
      printf("Invalid choice. Please enter a number between 1 and 5.\n");
    }
  } while (choice != 5);
  return 0;
}