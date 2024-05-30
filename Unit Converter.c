#include <stdio.h>

void lengthConversion();
void weightConversion();
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                lengthConversion();
                break;
            case 2:
                weightConversion();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\nUnit Converter\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Exit\n");
}

void lengthConversion() {
    int choice;
    float value, convertedValue;

    printf("\nLength Conversion\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Meters\n");
    printf("3. Inches to Feet\n");
    printf("4. Feet to Inches\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter value in meters: ");
            scanf("%f", &value);
            convertedValue = value / 1000;
            printf("%.2f meters is %.2f kilometers\n", value, convertedValue);
            break;
        case 2:
            printf("Enter value in kilometers: ");
            scanf("%f", &value);
            convertedValue = value * 1000;
            printf("%.2f kilometers is %.2f meters\n", value, convertedValue);
            break;
        case 3:
            printf("Enter value in inches: ");
            scanf("%f", &value);
            convertedValue = value / 12;
            printf("%.2f inches is %.2f feet\n", value, convertedValue);
            break;
        case 4:
            printf("Enter value in feet: ");
            scanf("%f", &value);
            convertedValue = value * 12;
            printf("%.2f feet is %.2f inches\n", value, convertedValue);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

void weightConversion() {
    int choice;
    float value, convertedValue;

    printf("\nWeight Conversion\n");
    printf("1. Grams to Kilograms\n");
    printf("2. Kilograms to Grams\n");
    printf("3. Pounds to Kilograms\n");
    printf("4. Kilograms to Pounds\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter value in grams: ");
            scanf("%f", &value);
            convertedValue = value / 1000;
            printf("%.2f grams is %.2f kilograms\n", value, convertedValue);
            break;
        case 2:
            printf("Enter value in kilograms: ");
            scanf("%f", &value);
            convertedValue = value * 1000;
            printf("%.2f kilograms is %.2f grams\n", value, convertedValue);
            break;
        case 3:
            printf("Enter value in pounds: ");
            scanf("%f", &value);
            convertedValue = value * 0.453592;
            printf("%.2f pounds is %.2f kilograms\n", value, convertedValue);
            break;
        case 4:
            printf("Enter value in kilograms: ");
            scanf("%f", &value);
            convertedValue = value / 0.453592;
            printf("%.2f kilograms is %.2f pounds\n", value, convertedValue);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}
