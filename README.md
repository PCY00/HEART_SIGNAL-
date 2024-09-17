# HeartSignal

## Language Selection

[English](README.md) | [한국어](README_KR.md)

<br><br>

## [Go directly to used data](https://github.com/PCY00/HEART_SIGNAL-/tree/main/HeartSignal/data/heart_rate_measurement)

<br><br>

## Overview

### Problem Identification
- During weight training, rest periods between sets are essential; inappropriate rest times can reduce exercise efficiency.
- Since recovery rates vary among individuals, standard rest times may not be suitable for everyone.
- There may be uncertainty about whether the exercise is being performed at the right intensity or how to execute the exercises correctly.
- A device that provides personalized rest times and checks if the exercise intensity is appropriate could enhance exercise efficiency.

<br>

### Solution
- Heart rate increases during exercise and decreases during rest. Thus, there is an association between rest and heart rate.

- Research shows that while there was no difference in total exercise volume between heart rate-based rest times and fixed rest times, the heart rate-based rest time was shorter.
  - (심박수기준 세트간 휴식조건에 따른 벤치프레스 운동시 휴식시간, 반복횟수, 총운동량, 및 근통증에 미치는 영향, 정환종, 최종인, 김기홍,한국스포츠학회  한국스포츠학회지  제18권 제4호  2020.12 pp.997-1008)

- Using heart rate-based rest methods is more efficient, and since heart rate recovery varies between individuals, it provides a more personalized rest time.
  - Standard heart rate is set at 101-105
  - (Costill, D. L., Kenney, W. L., & Wilmore, J. (2008). Physiology of sport and exercise (Vol. 448, p. 449). Human kinetics.)

- While specific research on the number of repetitions or weights for hypertrophy is scarce, there are studies indicating that appropriate exercise tempo can be effective for hypertrophy.
  - (The Influence of Movement Tempo During Resistance Training on Muscular Strength and Hypertrophy Responses: A Review, 2021, Sports Medicine)

- The Karvonen formula is used to determine exercise intensity:
  - Maximum Heart Rate = 220 - Age
  - Target Heart Rate for Exercise = {(Maximum Heart Rate - Resting Heart Rate) X Exercise Intensity (%) } + Resting Heart Rate

<br><br>

## Modeling and Actual Photos
<div align="center">
  
  | Modeling | Actual |
  |:---:|:---:|
  | <img src="https://github.com/user-attachments/assets/f33ba7d8-d844-4683-86ca-b2c6476bfc70" width="300px" height="300px" alt="Modeling"> | <img src="https://github.com/user-attachments/assets/76339354-688e-4d6e-ae65-061b71928745" width="300px" height="300px" alt="Installation"> |
</div>

<br><br>

### Deep Learning-Based Rest Time Estimation Video

- The app part is not included; designed and developed using App Inventor, so the design and performance are suboptimal.

[Deep Learning-Based Rest Time Estimation Video](https://youtube.com/shorts/TX3P9vqnglA)

<br><br>

## Directory Format

```
HeartSignal/
├── Document/
│   ├── presentation_materials.pptx
│   │
├── APP/
│   ├── app.jpg
│   ├── app_code.jpg
│   │
├── arduino/
│   ├── HW_code.ino
│   │
├── data/
│   ├── data_csv.py
│   ├── heart_rate_measurement
│   │    ├── 박찬영
│   │    ├── 정민섭
│   │    ├── 최대영

```


<br><br>

## Hardware Used

| Equipment Name       | Specifications                                                                                                  | Quantity | Notes                         |
|:--------------------:|:---------------------------------------------------------------------------------------------------------------:|:--------:|:-----------------------------:|
| WeMos D1 MINI Pro   | ESP8266EX 172017 PCUB49                                                                                         | 1        |                               |
| Power Charging Shield|                                                                                                               | 1        | Charging shield for D1 Mini Pro |
| Lithium Polymer Battery | Battery                                                                                                      | 1        | 245mAh                        |
| HW-605              | MAX30102                                                                                                      | 1        | Heart rate measurement sensor  |

<br><br>
