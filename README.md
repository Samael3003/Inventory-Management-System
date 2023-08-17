
# Building an Open-Source Inventory Management and Monitoring System for Efficient Operations 📦🔍🌐

Introduction:
Managing inventories efficiently is crucial for businesses of all sizes. To streamline this process, we have developed an innovative Inventory Management and Monitoring System as part of our Engineering Design and Innovation Project. This system incorporates open-source technologies and a user-friendly approach to help businesses effectively manage their inventory, optimize operations, and enhance overall productivity. 🚀💼🔧

## 1. Inventory Management System with Raspberry Pi 🍓🥧

Our system leverages the power of Raspberry Pi, a popular single-board computer, to create a robust and versatile inventory management solution. Here's how it works: 🖥️📊🤖

### a. Hardware Setup 🛠️
We utilize Raspberry Pi 4B and connect it to three ultrasonic sensors, one for each rack. These sensors measure the distance within the racks, continuously monitoring inventory levels.

### b. Software Setup 💻🔌
We set up the Raspberry Pi with the Raspbian operating system, an open-source OS specifically designed for Raspberry Pi. Additionally, we install essential Python libraries like RPi.GPIO and smtplib for sensor interfacing and email communication.

### c. Sensor Measurement and Billing 📏💰
Using Python code, we measure the distance from the ultrasonic sensors and calculate the bill based on the reduced distance when an item is removed from the rack. The bill is stored in a .txt file in the Raspberry Pi's file system. We utilize the smtplib library to send the bill to the customer via email, ensuring prompt and accurate updates. 📧💳📝

```py
import RPi.GPIO as GPIO
import smtplib

# Initialize GPIO pins for ultrasonic sensors
# Configure SMTP server details for email notification

def measure_distance(sensor_pin):
    # Function to measure distance using ultrasonic sensor
    # Trigger the sensor, calculate distance based on the pulse duration
    return distance

def calculate_bill(distance):
    # Function to calculate the bill based on the reduced distance
    # Implement the necessary logic for bill calculation
    return bill_amount

def store_bill(bill):
    # Function to store the bill in a .txt file on Raspberry Pi
    # Open the file in append mode and write the bill amount
    pass

def send_email(bill):
    # Function to send the bill to the customer via email
    # Create the email message with the bill details
    # Connect to the SMTP server and send the email
    pass

try:
    # Set up GPIO pins and sensor configurations

    while True:
        for rack in racks:
            # Measure the distance using ultrasonic sensor for each rack
            distance = measure_distance(rack.sensor_pin)

            if distance < threshold:
                # Object removed from the rack
                bill = calculate_bill(distance)
                store_bill(bill)
                send_email(bill)
                # Wait for some time before checking the next rack

finally:
    # Clean up GPIO pins and resources

```

## 2. Inventory Management System with NodeMCU ESP8266 📲🌐📉

Expanding the system's capabilities, we incorporate the NodeMCU ESP8266 board to enable real-time inventory monitoring and alerting. Here's an overview: 

### a. Hardware Setup 🛠️
We connect the NodeMCU ESP8266 board to two ultrasonic sensors, which are housed in racks containing perishable goods. This configuration allows us to continuously monitor the inventory levels in these racks.

### b. Software Setup 💻🔌
We install the necessary libraries such as ESP8266WiFi and ThingSpeak in the Arduino IDE, an open-source integrated development environment for programming microcontrollers.

### c. ThingSpeak Integration and Alert System 📊📮🚨
By leveraging the ThingSpeak cloud platform and its write API, we update inventory data every minute. This information is then relayed to the IFTTT API, which triggers an email notification to the inventory manager when certain goods reach minimal supply levels. This real-time alert system enables proactive inventory management and timely replenishment. 🌩️📩📉

```ts
-- Import required libraries
require("wifi")
http = require("http")

-- Configure Wi-Fi network
wifi.setmode(wifi.STATION)
wifi.sta.config("SSID", "password")  -- Replace SSID and password with your network credentials

-- Configure ThingSpeak API details
api_key = "YOUR_THINGSPEAK_API_KEY"
base_url = "http://api.thingspeak.com/update?api_key=" .. api_key

-- Configure IFTTT API details
ifttt_webhook_url = "YOUR_IFTTT_WEBHOOK_URL"

-- Configure sensor pins
trigger_pin1 = 1  -- GPIO1
echo_pin1 = 2     -- GPIO2
trigger_pin2 = 3  -- GPIO3
echo_pin2 = 4     -- GPIO4

-- Configure inventory thresholds
inventory_threshold1 = 10  -- Threshold for rack 1
inventory_threshold2 = 15  -- Threshold for rack 2

-- Function to send HTTP POST request to IFTTT API
function sendEmailAlert()
    -- Implement HTTP POST request to IFTTT API with email alert payload
end

-- Function to measure distance using ultrasonic sensor
function measureDistance(trigger_pin, echo_pin)
    -- Implement logic to measure distance using ultrasonic sensor
    -- Return the measured distance
end

-- Main loop
while true do
    -- Measure distance from ultrasonic sensors
    distance1 = measureDistance(trigger_pin1, echo_pin1)
    distance2 = measureDistance(trigger_pin2, echo_pin2)
    
    -- Update ThingSpeak channel with inventory information
    -- Send HTTP GET request to ThingSpeak API with updated inventory data
    
    -- Check inventory levels and send email alerts if below thresholds
    if distance1 < inventory_threshold1 then
        sendEmailAlert()
    end
    
    if distance2 < inventory_threshold2 then
        sendEmailAlert()
    end
    
    -- Delay for 1 minute
    delay(60000)
end

```

## 3. Inventory Monitoring System with Arduino UNO ⚠️💡🌡️

To ensure the safety and integrity of inventories, we incorporate an Arduino UNO board with various sensors. Here's how it works: 

### a. Hardware Setup 🛠️
We connect a DHT11 sensor for temperature and humidity measurement, as well as an MQ135 sensor for smoke detection. These sensors enable real-time monitoring of environmental conditions.

### b. Software Setup 💻🔌
We utilize the Arduino IDE and install relevant libraries to facilitate LCD display interaction and sensor readings.

### c. Safety Measures and Display 📊🌡️🔴
When abnormal readings are detected, such as high temperatures or smoke presence, the LCD display shows a "Danger" message, the Arduino triggers a fan, a buzzer sounds, and red LEDs light up. These safety measures help prevent inventory damage and ensure the well-being of personnel. ⚠️🌡️🔴🔒

```ts
#include <dht11.h>  // Include DHT11 sensor library
#define DHT11_PIN 2 // Define the pin for DHT11 sensor
dht11 DHT11;       // Create an instance of the DHT11 sensor

// Pin definitions for fan, buzzer, and LEDs
#define FAN_PIN 3
#define BUZZER_PIN 4
#define RED_LED_PIN 5

void setup() {
  // Initialize the LCD display, fan, buzzer, and LEDs
  // Set the appropriate pins as input or output
  // Set up any necessary communication protocols (I2C, etc.)
}

void loop() {
  // Read temperature and humidity from the DHT11 sensor
  int result = DHT11.read(DHT11_PIN);
  if (result == DHTLIB_OK) {
    float temperature = DHT11.temperature;
    float humidity = DHT11.humidity;

    // Display temperature and humidity readings on the LCD
    // Update the display in real-time
    // Use appropriate LCD library functions

    // Check for abnormal readings
    if (temperature > MAX_TEMPERATURE || humidity > MAX_HUMIDITY) {
      // Abnormal reading detected
      // Trigger safety measures
      lcd.print("Danger");

      // Turn on the fan
      digitalWrite(FAN_PIN, HIGH);

      // Sound the buzzer
      digitalWrite(BUZZER_PIN, HIGH);

      // Turn on the red LEDs
      digitalWrite(RED_LED_PIN, HIGH);
    } else {
      // Normal readings
      // Turn off the fan, buzzer, and LEDs
      digitalWrite(FAN_PIN, LOW);
      digitalWrite(BUZZER_PIN, LOW);
      digitalWrite(RED_LED_PIN, LOW);
    }
  } else {
    // Error reading from the DHT11 sensor
    // Handle the error condition
  }

  // Delay for a certain period of time before the next reading
  delay(1000);
}

```


## Advantages and Applications 🌟📈💼

Our Inventory Management and Monitoring System offers numerous benefits and applications:

1. Real-time inventory monitoring allows for efficient management and proactive decision-making.
2. Temperature and humidity monitoring ensures optimal storage conditions, preventing spoilage and maintaining quality.
3. Gas level monitoring enhances safety by detecting potential hazards in the inventory environment.
4. Open-source nature encourages transparency, affordability, and community collaboration.
5. Customizable and modular design enables adaptation to different business sizes and needs.
6. On-the-spot billing system improves customer experience and reduces waiting times.
7. Data collection facilitates analysis for demand patterns, inventory optimization, and informed decision-making.

## Conclusion:
Our Inventory Management and Monitoring System, driven by open-source technologies, empowers businesses to effectively monitor inventories, automate billing processes, implement proactive alerts, and maintain optimal storage conditions. With its user-friendly approach and customizable features, this system offers an innovative solution for businesses of all sizes. Embrace the power of open-source and revolutionize your inventory management practices today! 🚀📦🌐

### THE TEAM :
![image](https://github.com/Auriel3003/samael/assets/103866475/992298ba-a666-4959-a003-9a4d155c0474)
![image](https://github.com/Auriel3003/samael/assets/103866475/76f9f425-5ea2-420e-93c1-f7182097b472)

### The Functional Representation :
![image](https://github.com/Auriel3003/samael/assets/103866475/bafc347b-d338-4bc5-b52a-4803a9fc6258)
![image](https://github.com/Auriel3003/samael/assets/103866475/8191a17b-188e-4736-a574-2823c97bd48f)
![image](https://github.com/Auriel3003/samael/assets/103866475/3acc22cb-1dd5-4f94-a741-34fa69e59658)

### Partner Project with my Collegue:
![image](https://github.com/Auriel3003/samael/assets/103866475/2a18279f-d8d0-4654-bd04-e84febe52c24)

![image](https://github.com/Auriel3003/samael/assets/103866475/616e586f-1629-49f3-ae73-c8bbcdb30021)
![image](https://github.com/Auriel3003/samael/assets/103866475/f9ccdd63-d1d2-4c4f-889b-922ce6583b28)
