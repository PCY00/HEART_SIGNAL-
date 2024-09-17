# Heart Rate Measurement Data

## Language Selection

[English](README.md) | [한국어](README_KR.md)

<br><br>

## Equipment and Data Collection Method

- **Current Equipment**:
  - **MAX30102**: Inaccurate
  - **ECG**: Inaccurate

- **Alternative Equipment**:
  - **Galaxy Watch 4**:
    - **Method**: Real-time heart rate measurement during exercise via the Samsung Health app
    - **Data Format**: Can be extracted as a JSON file
    - **Limitation**: Cannot measure rest times between sets

## Data Processing Method

- **Data Types**: Divided into exercise and rest periods between sets
- **Data Format**: String format
- **Format**:
  - Date & Time
  - Resting Heart Rate
  - Average Heart Rate
  - Max Heart Rate
  - Real-time Heart Rate

## Data Processing

- **Filename**: `data_csv.py`
- **Function**: Processes JSON data into CSV format
