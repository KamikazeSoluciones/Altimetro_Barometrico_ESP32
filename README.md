Altímetro Barométrico on ESP32

Este dispositivo es un proyecto experimental de altímetro barométrico diseñado para estimar la altura entre 
dos puntos mediante la diferencia de presión atmosférica, utilizando un sensor BME280 y un microcontrolador ESP32. 
La lectura se muestra en una pantalla OLED.

Este dispositivo fue probado en terreno en varios puntos icónicos de París: 
Torre Eiffel 
Arco del Triunfo.
Museo de Louvre
Río Sena

🚀 Objetivo

Explorar el uso de sensores barométricos para medir alturas reales, como una evolución de métodos tradicionales 
(por ejemplo, estimar la altura de edificios según el número de pisos). Además, es un proyecto ideal para enseñar 
física, presión atmosférica y electrónica aplicada.

📸 Ejemplo de Medición en la Torre Eiffel

- Presión atmosférica marcada en la base: 1017,6 hPa  
- Presión atmosférica marcada en el segundo piso: 1003,83 hPa  
- Altura estimada: 113,1 m  
- Altura oficial: 116 m  

🧰 Componentes utilizados
<img width="1920" height="1080" alt="Image" src="https://github.com/user-attachments/assets/4f4f1c76-32a2-4e71-a90b-94f1b2701fd5" />

- ESP32 (Business Card Green Edition)
- Sensor BME280 (I2C)
- Pantalla OLED 128x64 (SSD1306)
- Pulsadores N.O.
- Power Bank
- Enclosure 3D impreso (modelado en SolidWorks)

⚙️ Funcionamiento

1. Al encender el dispositivo, se muestra la presión y temperatura actuales.
2. Se presiona el botón "Start" para registrar la presión inicial.
3. En otro punto, se presiona el botón "End" para registrar la nueva presión.
4. El sistema calcula la altura estimada según la fórmula barométrica.
5. Los datos se muestran en la pantalla Oled.

🧮 Fórmula usada

<img width="344" height="93" alt="Image" src="https://github.com/user-attachments/assets/73b9b039-01e9-4746-a967-88878a19e0ac" />


🛠️ Para compilar

1. Abre el código con Arduino IDE o PlatformIO.
2. Instala las siguientes bibliotecas:

   - Adafruit BME280
   - Adafruit Sensor
   - Adafruit SSD1306
3. Ajusta los pines I2C si es necesario.
4. Sube el código al ESP32 y listo.

📦 Impresión 3D
- El diseño incluye una tapa avellanada para tornillos M3.
- Archivos disponibles en formato `.step` y `.stl`.
  
<img width="3307" height="2339" alt="Image" src="https://github.com/user-attachments/assets/d59ec4fd-f288-44a3-b9dc-2c2108761966" />

<img width="3307" height="2339" alt="Image" src="https://github.com/user-attachments/assets/ee7ec2f8-539e-42b5-b502-9efbbea8b800" />


✍️ Autor

Adrian Lara – Freelance en electrónica, diseño 3D y sistemas embebidos
🔗 Youtube: (https://www.youtube.com/@KamikazeSolucionesElectronicas)
📞 +351 911 180 717
