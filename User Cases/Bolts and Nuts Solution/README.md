# 🔩 Bolts & Nuts Inspection System

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Python](https://img.shields.io/badge/Python-3.x-blue?logo=python)](https://www.python.org/)
[![OpenCV](https://img.shields.io/badge/OpenCV-Computer_Vision-green?logo=opencv)](https://opencv.org/)

## 📝 Project Description
**Bolts & Nuts**, a manufacturer of metal components, aims to optimize its semi-automated packaging process. Currently, human errors caused by visual fatigue lead to packages with incorrect counts. This project proposes an **Automated Visual Inspection System** using Computer Vision to ensure final product quality.

---

## 🎯 Objectives
The system is designed to automatically validate the contents of packages on a specific production line, adhering to the following rules:

- [x] **Quality Standard:** Each set must contain exactly **10 bolts** and **10 nuts**.
- [x] **Image Processing:** RGB image capture and analysis for object detection.
- [x] **Immediate Feedback:** Issuance of status (**Approved/Rejected**) after analysis.
- [x] **Error Reporting:** If rejected, the system indicates exactly how many items are missing or extra.

---

## 📸 Test References

### Sample Analyzed Set
<img src="https://github.com/jrafa1607/Computational-Vision-In-Python/blob/main/Bolts%20and%20Nuts%20Solution/Anexos/img00.jpg" width="400">

### Reference Key
<img src="https://github.com/jrafa1607/Computational-Vision-In-Python/blob/main/Bolts%20and%20Nuts%20Solution/Anexos/Gabarito.jpeg" width="400">

---

## 🛠 Technologies Used
* **Language:** Python
* **Main Library:** OpenCV
* **Concepts:** Segmentation, Contour Detection, Thresholding.

---
