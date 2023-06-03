#include <Arduino_FreeRTOS.h>  // Include the FreeRTOS library
#include <task.h>             // Include the task creation functions

// Pin for the LED
const int ledPin = 13;
const int ledPin1 = 3;

// Function declarations
void task1(void *pvParameters);
void task2(void *pvParameters);
void task3(void *pvParameters);

// Task handles
TaskHandle_t task1Handle;
TaskHandle_t task2Handle;
TaskHandle_t task3Handle;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);  // Set the LED pin as an output
  pinMode(ledPin1, OUTPUT);
  // Create Task 1
  xTaskCreate(task1, "Task 1", 128, NULL, 2, &task1Handle);

  // Create Task 2
  xTaskCreate(task2, "Task 2", 128, NULL, 2, &task2Handle);
  xTaskCreate(task3, "Task 3", 128, NULL, 2, &task3Handle);
}

void loop() {
  // Nothing to do here, as tasks are running in parallel
}

// Task 1 function
void task1(void *pvParameters) {
  while (1) {
    digitalWrite(ledPin, HIGH);  // Turn on the LED merah
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Delay for 1 second
    digitalWrite(ledPin, LOW);  // Turn off the LED
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // Delay for 1 second
  }
}

// Task 2 function
void task2(void *pvParameters) {
  while (1) {
    digitalWrite(ledPin1, HIGH);  // Turn on the LED biru
    vTaskDelay(500 / portTICK_PERIOD_MS);  // Delay for 0.5 seconds
    digitalWrite(ledPin1, LOW);  // Turn off the LED
    vTaskDelay(500 / portTICK_PERIOD_MS);  // Delay for 0.5 seconds
  }
}

void task3(void *pvParameters) {
  while (1) {
    Serial.println("YUTIWAY IS DA BEST");
    vTaskDelay(3000 / portTICK_PERIOD_MS);
  }
}
