# 🤖 TROLL-E – Human Following Robot

**TROLL-E** is a simple and effective **human-following robot** built using Arduino and IoT sensors. It is designed to follow a person based on distance and direction using **ultrasonic and IR sensors**, making it ideal for personal assistance, autonomous delivery, and smart mobility applications.

---

## 🎯 Key Features

- 🚶‍♂️ Human-following behavior using real-time sensor input
- 🔊 Buzzer alert when reversing for safety
- ⬅️➡️ IR sensor-based path correction (left/right turning)
- 🔁 Dynamic response based on distance zones:
  - **0–7 cm** → Moves backward + buzzer alert
  - **7–15 cm** → Stops and waits
  - **15–25 cm** → Moves forward
- 🔄 Servo-mounted ultrasonic sensor for wider detection range

---

## 🧩 Components Used

| Component | Function |
|----------|----------|
| Arduino UNO | Main controller |
| Ultrasonic Sensor (HC-SR04) | Measures distance |
| IR Sensors | Detects directional movement |
| Servo Motor | Rotates ultrasonic sensor |
| L293D Motor Driver | Controls DC motors |
| DC Motors | Drive the robot |
| Buzzer | Alerts when reversing |

---

## ⚙️ Working Mechanism

- The ultrasonic sensor detects the distance from the target (human).
- Based on the range:
  - The robot moves **forward**, **stops**, or **reverses**.
- IR sensors guide **left** or **right** motion based on side detection.
- A servo motor rotates the ultrasonic sensor for wider scanning.
- A buzzer activates when the robot moves backward for safety.

---

## 🚀 Applications

- 🧓 Assisting elderly or disabled individuals
- 📦 Delivery robots for warehouses
- 🛡️ Security patrolling bots
- 🏭 Industrial automation (smart carts)

---

## 🌟 Future Enhancements

- Add AI-based tracking for more accurate following
- Camera module for facial or color-based recognition
- Wireless control or app integration

---

## 👨‍💻 Team Members

- Kavya V Baliga – 2022BEC0009  
- Vagish Bhardwaj – 2022BEC0022  
- Kanha Jaiswal – 2022BEC0039  
- Aryan Kardam – 2022BEC0040  
- Nishant Gaur – 2022BEC0042

---

> 🚀 This project was built as part of our academic coursework to demonstrate basic IoT robotics with real-world utility. For any suggestions or contributions, feel free to fork this repository or raise an issue.
