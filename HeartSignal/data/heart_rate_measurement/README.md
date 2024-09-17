# Data Measurement and Processing

## Language Selection

[English](README.md) | [한국어](README_KR.md)

<br><br>

## file
- The following three folders are data based on heart rate based on
   - 박찬영
   - 정민섭
   - 최대영
  


<br><br>

## Data Measurement Method

1. **Wearing the Galaxy Watch**:
   - Make sure the watch is tightly worn on your wrist.
   - Measure your heart rate to record your resting heart rate.
   - Open the Samsung Health app on the Galaxy Watch.
   - Select the "Exercise" option.
   - Choose "Strength Training" (for bench press).
   - After the 3-2-1 countdown, start your workout.
   - Perform 4 sets of 10 reps at 60% of your 1RM for bench press.
   - After completing the workout, swipe left to find the "End" button and stop the data measurement.

   **Data Measurement Video**:
   [Watch the video](https://youtube.com/shorts/HP1Lgp2Oono?feature=share)

   **Important Notes**:
   - Do not pause the heart rate measurement after each set, as we need to record the heart rate throughout the entire workout and rest periods.
   - Avoid talking during rest periods for more accurate data.
   - Use a stopwatch to:
     - Check the workout start time.
     - Check the workout end time.
     - Check 5 seconds before the end of the rest period (90 seconds) and immediately start the next set.

   **Example Image**:
   
   ![Example](https://github.com/user-attachments/assets/06a42bee-0920-45f0-82e1-d298a85c20b6)

## How to Retrieve the Data

1. **Accessing the Data**:
   - Open the Samsung Health app on your Galaxy phone.
   - Tap the three vertical dots to access the settings.
   - Scroll down and select "Download personal data."
   - You'll need your Samsung account password for the download.

2. **Extracting the Data**:
   - After downloading, locate the JSON file.
   - Compress the "exercise" folder and send it to yourself via KakaoTalk.

   **How to Retrieve Data Video**:
   [Watch the video](https://youtu.be/mee9Ge_fe1U)

## Saving the Retrieved Data to a CSV File

1. **Setup and Preparation**:
   - Install Visual Studio Code.
   - Download and install Python: [Installation Guide](https://wikidocs.net/187040).

2. **Processing the Data**:
   - Copy the code from [GitHub Repository](https://github.com/PCY00/Inbody_2023/tree/main/data).
   - Create a `code.py` file in Visual Studio Code and paste the code.
   - Replace the placeholder with your extracted data (from the unzipped folder), then run the Python script.

   **Unix Timestamp Conversion Website**:
   [Convert here](https://time.is/ko/Unix%20time%20converter)

   - Remove the last three digits from the timestamp.

   **Saving Data to CSV Video**:
   [Watch the video](https://youtu.be/0HgWgeoy-Hc)

## Data Classification Method

1. **Opening the CSV File**:
   - Open the generated `data.csv` file in Visual Studio Code.
   - Mark the end of each workout set with `///` above, and after each rest period with `///` below.

   - This is to separate workout and rest periods.
   - Since there are 4 sets, you will need to insert `///` three times.

2. **Renaming the File**:
   - Rename the CSV file using the measurement date and time.
   - Example: `2023072212` (year, month, day, hour)

   **Data Classification Video**:
   [Watch the video](https://youtu.be/t_aJSXOJGAk)

## Data Entry Method

1. **Viewing the CSV Data**:
   - The data in the CSV file will appear as follows:
   
   ![Example Image](https://github.com/user-attachments/assets/aedc9f23-de15-42e1-8b11-f8ef3f51adfa)
   ![Image](https://github.com/user-attachments/assets/627a8cd5-6662-43a5-91c5-432f4d6b47a2)

2. **Entering Data**:
   - In columns 3, 4, and 5, respectively, input the resting heart rate, max heart rate, and min heart rate.
   - Enter the resting heart rate measured before the workout.
   - You can easily calculate the max and min heart rates using the following formulas:
     - `=MAX(B:Click)` (for max heart rate)
     - `=MIN(B:Click)` (for min heart rate)

   ![Image](https://github.com/user-attachments/assets/6f9088a1-a48a-4bca-bffd-36cd18d1db2b)
   ![Image](https://github.com/user-attachments/assets/f2d87415-0f18-4ef9-a022-28953f0d6e06)
   ![Image](https://github.com/user-attachments/assets/4cc53e2f-037b-4067-84a2-b03b8764d957)

## Additional Information

- Only data from the past 2 weeks to 3 months can be downloaded.
