# nucleo-l4r5zi-sine-cube-ai

This project is an example how to implement a Machine Learning model on tiny microcontrollers. 

- The Machine Learning model was trained using generated sine data from Hello World example on tensorflow: https://github.com/tensorflow/tensorflow/tree/master/tensorflow/lite/micro/examples/hello_world/train

- In this project, we used the X-CUBE-AI to run inference on a pre-trained neural network. X-CUBE-AI supports models trained with TensorFlow, Keras, PyTorch, Caffe and others. Regardless of what you use to train the model, the model file needs to be in Keras (.h5), TensorFlow Lite (.tflite), or ONNX (.onnx) format.

- The project was inspired from the article - ["TinyML: Getting Started with STM32 X-CUBE-AI"](https://www.digikey.com/en/maker/projects/tinyml-getting-started-with-stm32-x-cube-ai/f94e1c8bfc1e4b6291d0f672d780d2c0)

References:
1. [Overview of X-CUBE-AI](https://www.st.com/en/embedded-software/x-cube-ai.html)
2. [X-CUBE-AI data brief](https://www.st.com/resource/en/data_brief/x-cube-ai.pdf)
3. [Getting Started with X-CUBE-AI](https://www.st.com/resource/en/user_manual/dm00570145-getting-started-with-xcubeai-expansion-package-for-artificial-intelligence-ai-stmicroelectronics.pdf)
4. [About STM32Cube.AI](https://blog.st.com/stm32cubeai-neural-networks/)
