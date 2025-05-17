# UART String Transmit & Receive

This project demonstrates basic **UART communication** using a PIC16F887 microcontroller. It receives a string over UART and responds with a predefined reply.

---

## 📁 Files

- **UART_String.X/** – MPLAB X project files  
- **UART_String.pdsprj** – (Optional) Proteus simulation file  

---

## 🧰 Requirements

- MPLAB X IDE  
- XC8 Compiler  
- PIC16F887  
- USB to Serial Converter (FTDI or CP2102)  
- Serial Terminal (e.g., PuTTY, Tera Term)  
- 20MHz Crystal

---

## 🔌 UART Settings

- **Baud Rate:** 9600  
- **TX:** RC6  
- **RX:** RC7  
- **Crystal Frequency:** 20MHz (`_XTAL_FREQ 20000000`)

---

## 💡 What It Does

- Waits for a string from the user via UART  
- If the user sends `"ashna"` → responds with `"anees"`  
- If the user sends `"anees"` → responds with `"ashna"`  
- Adds a newline after each response

---

## 🔁 Example

**You send:**  
```
ashna
```

**Microcontroller replies:**  
```
anees
```

**You send:**  
```
anees
```

**Microcontroller replies:**  
```
ashna

