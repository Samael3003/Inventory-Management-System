import RPi.GPIO as GPIO
import time

# GPIO Pins
sensor1_trigger = 17
sensor1_echo = 27

sensor2_trigger = 23
sensor2_echo = 24

sensor3_trigger = 5
sensor3_echo = 6

button_pin = 16

# Setup GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(sensor1_trigger, GPIO.OUT)
GPIO.setup(sensor1_echo, GPIO.IN)

GPIO.setup(sensor2_trigger, GPIO.OUT)
GPIO.setup(sensor2_echo, GPIO.IN)

GPIO.setup(sensor3_trigger, GPIO.OUT)
GPIO.setup(sensor3_echo, GPIO.IN)

GPIO.setup(button_pin, GPIO.IN, pull_up_down=GPIO.PUD_UP)

def measure_distance(trigger_pin, echo_pin):
    GPIO.output(trigger_pin, True)
    time.sleep(0.00001)
    GPIO.output(trigger_pin, False)

    pulse_start = time.time()
    pulse_end = time.time()

    while GPIO.input(echo_pin) == 0:
        pulse_start = time.time()

    while GPIO.input(echo_pin) == 1:
        pulse_end = time.time()

    pulse_duration = pulse_end - pulse_start
    distance = pulse_duration * 17150
    distance = round(distance, 2)

    return distance

def save_bill(items, total):
    timestamp = time.strftime("%Y-%m-%d_%H-%M-%S", time.localtime())
    file_name = f"bill_{timestamp}.txt"

    with open(file_name, "w") as file:
        file.write("Inventory Bill\n")
        file.write("Timestamp: " + timestamp + "\n\n")
        file.write("Items:\n")

        for item, quantity in items.items():
            file.write(item + " - " + str(quantity) + "\n")

        file.write("\nTotal: $" + str(total))

def print_inventory(items):
    print("Current Inventory:")
    for item, quantity in items.items():
        print(item + ": " + str(quantity))

try:
    items = {
        "Item 1": 0,
        "Item 2": 0,
        "Item 3": 0
    }

    print("Inventory Management App")
    print("------------------------")

    while True:
        print("\n1. Scan Inventory")
        print("2. Print Inventory")
        print("3. Save Bill")
        print("4. Quit")
        choice = input("Enter your choice: ")

        if choice == "1":
            # Perform inventory scan
            items["Item 1"] = measure_distance(sensor1_trigger, sensor1_echo)
            items["Item 2"] = measure_distance(sensor2_trigger, sensor2_echo)
            items["Item 3"] = measure_distance(sensor3_trigger, sensor3_echo)
            print("Inventory scanned successfully!")

        elif choice == "2":
            print_inventory(items)

        elif choice == "3":
            total = sum(items.values())
            save_bill(items, total)
            print("Bill saved successfully!")

        elif choice == "4":
            break

except KeyboardInterrupt:
    GPIO.cleanup()
