# Automated LEGO Sorter & Classifier (In Progress)

An automated mechatronic sorting system designed to classify LEGO bricks using optical sensing, dynamic actuation, and custom structural framing.

---

## 🛠 System Architecture & Tech Stack
Microcontroller: Arduino / Microcontroller
Sensor: Adafruit APDS9960
Actuation: mini stepper motor-200 steps-20x30 NEMA-8 Size,Mini Servo (SG90)
Software: C++ / Embedded C
Mechanical:** Custom physical chassis (Iterative prototyping)

---

## 📸 Current Progress
*(Upload 1–2 photos of your physical build and breadboard layout into the `media/` folder and link them here)*

![Physical Build](media/current_build.jpg)

---

## 🔬 Mechanical & Electrical Iterations
* **Chassis Redesign:** Completed 3 structural iterations (1 major redesign, 2 minor adjustments) to improve gravity-fed alignment and part flow.
* 
* **Iteration 1 — Passive Gravity Feed & Optical Calibration Challenges:**
  * *Attempt:* Originally attempted to read optical color data on-the-fly as LEGO bricks slid freely down a gravity ramp.
  * *Bottleneck:* Calibrating the APDS-9960 sensor proved nearly impossible—motion blur, inconsistent object speeds, and ambient light interference made software thresholding unreliable on fast-moving parts.

* **Iteration 2 — Active Escapement Pivot (9g Servo Staging Gate):**
  * *Solution:* Realized that physical motion was the root cause of the sensor noise. Redesigned the intake to incorporate a 9g micro servo staging gate.
  * *Result:* The servo holds each piece completely stationary directly in front of the sensor for a clean, noise-free optical reading before releasing it down the ramp to the stepper sorting wheel.

## 🚀 Next Steps
- [x] Physical chassis structure baseline
- [x] Sensor integration on breadboard
- [ ] Finalize sensor filtering & calibration logic
- [ ] Complete end-to-end sorting tests
- [ ] Add CAD files and wiring schematics to repo
