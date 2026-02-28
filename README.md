# ✈ AeroNex — Airline Management System

A full-featured airline management system with a premium web interface and a C++ console backend.

## Project Files

| File | Description |
|------|-------------|
| `index.html` | Complete web application (HTML + CSS + JavaScript, single file) |
| `aeronex_backend.cpp` | Original C++ console application |

## Web App Features
- 🛡 **Admin Panel** — Add, edit, delete flights; view all bookings (password: `w1&a2`)
- 🧳 **Passenger Portal** — Browse flights, book tickets, cancel bookings
- 🇵🇰 **10 pre-loaded Pakistani domestic routes** (KHI, LHE, ISB, PEW, UET, MUX, SKT…)
- 📊 Live stats dashboard — flights, bookings, routes, revenue
- 🔍 Real-time search on all panels
- 💾 Data persisted via `localStorage`

## How to Run

### Web App
Simply open `index.html` in any modern browser. No server needed.

### C++ Backend
```bash
g++ -std=c++11 aeronex_backend.cpp -o aeronex
./aeronex
```

## Admin Password
```
w1&a2
```

---
Built by **Wajahat147** · AeroNex Airline Management System © 2026
