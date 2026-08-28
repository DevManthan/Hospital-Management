# Smart Hospital Priority Management System

A high-performance emergency triage and hospital queuing system built in **C** using dynamic memory allocation and **Priority Queues ( Linked Lists)**.

---

## 📌 Project Overview

Standard First-In-First-Out (FIFO) queues fail in hospital emergency rooms where patient severity varies drastically. 

The **Smart Hospital Priority Management System** solves this by implementing an automated **Priority-Based Triage Queue**:
* **Priority 1 (Critical):** Immediate treatment; jumps directly to the head of the line.
* **Priority 2 (Serious):** Placed ahead of standard routine consultations.
* **Priority 3 (Normal):** Handled sequentially following standard FIFO order.

---

## ✨ Key Features

* **Priority-Based Enqueue ($O(n)$):** Automatic queue reordering based on severity level while preserving arrival order (FIFO) among identical priorities.
* **Instant Treatment / Dequeue ($O(1)$):** Constant-time head removal for rapid doctor calls.
* **Interactive CLI Queue Visualizer:** Real-time console table displaying patient ID, triage category, condition, and queue position.
* **Patient Lookup:** Linear search ($O(n)$) by unique Patient ID.
* **Audit Reporting:** Auto-logs daily statistics and treated patient metrics to `output_report.txt`.
* **Clean Memory Lifecycle:** Dynamic allocation via `malloc()` on admission and immediate deallocation via `free()` upon discharge to prevent leaks.

---

## 🏗️ Data Structures & Complexity

| Operation | Implementation | Time Complexity |
| :--- | :--- | :--- |
| **Enqueue (Admit)** | Priority-based sorted insert in Singly Linked List | $O(n)$ |
| **Dequeue (Treat)** | Head pointer extraction and node release | $O(1)$ |
| **Search Patient** | Linear traversal by `patientID` | $O(n)$ |
| **Display Queue** | Complete sequential list traversal | $O(n)$ |

---

## 📂 Project Structure

```text
HospitalManagementSystem/
├── src/
│   ├── main.c           # CLI Menu and execution loop
│   ├── patient.c        # Patient structure operations
│   ├── queue.c          # Priority queue mechanics (enqueue, dequeue, search)
│   └── report.c         # Daily metric generation & file export
├── include/
│   ├── patient.h
│   ├── queue.h
│   └── report.h
├── data/
│   └── output_report.txt # Runtime generated report log
├── Makefile             # Compilation rules
└── README.md
