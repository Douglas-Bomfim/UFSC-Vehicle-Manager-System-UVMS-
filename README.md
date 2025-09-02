# 🚗 UFSC Vehicle Manager System (UVMS)

A console-based application developed in **C++** to manage a fleet of vehicles.  
The system allows registering different types of vehicles (cars, buses, light trucks, and heavy trucks), logging trips associated with them, and maintaining a persistent history of the data in a file.

This project was created to apply **Object-Oriented Programming (OOP)** concepts such as **inheritance, polymorphism, and abstract classes**, as well as **file handling** to save and load the application state.

---

## 📖 About the Project
The **UFSC Vehicle Manager System (UVMS)** provides a complete management tool for handling vehicles and their trips.  
It ensures that every trip updates vehicle mileage automatically and that all data is saved and reloaded seamlessly between program executions.

---

## ✨ Features

### 🚙 Vehicle Registration
- **Cars** → Includes FIPE table value.  
- **Buses** → Specify transport type (e.g., urban, school).  
- **Light Trucks** → Includes cargo type.  
- **Heavy Trucks** → Includes number of axles.  

### 🛣️ Trip Logging
- Register new trips for any vehicle, specifying destination, distance, and fuel consumption.  
- Vehicle mileage is automatically updated after each trip.  

### 📊 Reports and Queries
- **General Report** → Displays all registered vehicles with details such as plate, description, initial and current mileage, average consumption, and type-specific data.  
- **Specific Search** → Search a vehicle by plate and view all its details, including a complete history of past trips.  

### 💾 Data Persistence
- **Save** → When exiting, all vehicle and trip data is saved to `save.txt`.  
- **Load** → On startup, data is automatically loaded from `save.txt`, allowing the session to continue seamlessly.  

---

## 🛠️ Code Structure
The project is organized into three main files:

- **`main.cpp`** → Contains the user interface (menu system) and main application logic.  
- **`vehicle.hpp`** → Declares the abstract base class `Vehicle` and derived classes `Car`, `Bus`, `LightTruck`, and `HeavyTruck`, establishing inheritance and polymorphism.  
- **`vehicle.cpp`** → Implements the constructors and methods defined in `vehicle.hpp`.  

---

## ⚙️ How to Use

### 1. Compile
Make sure to include all `.cpp` files in the compilation command. For example, using `g++`:

```bash
g++ main.cpp vehicle.cpp -o uvms.exe
