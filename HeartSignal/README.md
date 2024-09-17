# Additional Explanation

## Language Selection

[English](README.md) | [한국어](README_KR.md)

<br><br>

### Explanation

- This system provides personalized optimal rest times based on academic research. The expected benefit includes checking exercise intensity and providing advice if the intensity is too low.
- The Deep Learning model is trained using rest time and heart rate data collected over one week from three participants using the Galaxy Watch 4. This data is combined with 10,000 random numbers to train the model and predict the optimal rest times.
- The learned optimal rest times are sent to the IoT server Mobius, and this information is transmitted to the app for user access. (Note that the learned rest times are calculated using the previous day's data.)
- In the app, users start their workout by pressing a button and perform bench presses at 50% of their 1RM for 10 reps under the same conditions as described in the research. The received rest times are used to measure with a counter.
- The app guides the user to maintain the correct tempo using sound.
- A prototype exercise band has been created, which displays real-time heart rate data. Future plans include enabling the app's functionalities to operate on the exercise band.

