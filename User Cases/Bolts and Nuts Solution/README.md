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
<img src="https://github.com/jrafa1607/Computational-Vision-In-Python/blob/main/User%20Cases/Bolts%20and%20Nuts%20Solution/Analyzed%20Set%20(Sample).jpg">

### 📋 Reference Key (Test Data)
The table below presents the expected results for each image analyzed, including the count of bolts, nuts, and the calculated OTSU threshold value.

| Image | Bolts | Nuts | OTSU Threshold |
| :--- | :---: | :---: | :---: |
| Image 01 | 10 | 10 | 163.0 |
| Image 02 | 10 | 10 | 184.0 |
| Image 03 | 10 | 10 | 160.0 |
| Image 04 | 5 | 10 | 142.0 |
| Image 05 | 9 | 9 | 154.0 |
| Image 06 | 10 | 10 | 177.0 |
| Image 07 | 7 | 10 | 185.0 |
| Image 08 | 7 | 10 | 136.0 |
| Image 09 | 10 | 10 | 167.0 |
| Image 10 | 10 | 9 | 180.0 |
| Image 11 | 10 | 0 | 142.0 |
| Image 12 | 10 | 10 | 168.0 |
| Image 13 | 10 | 9 | 144.0 |
| Image 14 | 10 | 10 | 165.0 |
| Image 15 | 9 | 10 | 138.0 |
| Image 16 | 0 | 10 | 146.0 |
| Image 17 | 7 | 7 | 143.0 |
| Image 18 | 10 | 10 | 139.0 |
| Image 19 | 7 | 9 | 143.0 |
| Image 20 | 10 | 10 | 164.0 |

---

## 🛠 Technologies Used
* **Language:** Python
* **Main Library:** OpenCV
* **Concepts:** Segmentation, Contour Detection, Thresholding.

---
