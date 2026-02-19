# Sistema de Deteccion y Clasificacion Robotica con YOLO y ESP32

Sistema de vision artificial en tiempo real para la deteccion y clasificacion automatica de figuras impresas en 3D. Utiliza OpenCV y un modelo YOLO personalizado para identificar objetos y enviar comandos de control via comunicacion serial a un ESP32 que controla un brazo robotico para clasificar las piezas detectadas.

## Descripcion del Proyecto

Este sistema integra vision por computadora con robotica para automatizar el proceso de clasificacion de objetos. El flujo de trabajo consiste en:

1. **Deteccion**: Camara captura video en tiempo real
2. **Procesamiento**: Modelo YOLOv8 identifica y clasifica objetos (DINO, Hongo)
3. **Comunicacion**: Sistema envia comandos via serial al ESP32
4. **Actuacion**: Brazo robotico clasifica las piezas segun la deteccion

## Estructura del Proyecto

```
.
├── src/                    # Codigo fuente
│   ├── Inferencia.py       # Script de comunicacion serial con ESP32
│   └── YoloCV.ipynb        # Notebook de entrenamiento YOLO
├── hardware/               # Codigo para microcontroladores
│   └── Control del brazo.ino  # Firmware ESP32 para control del brazo
├── dataset/                # Datos de entrenamiento
│   └── Deteccion de figuras impresas 3D.v1-primera-prueba-honguito-y-dino.yolov8/
├── models/                 # Modelos entrenados
│   └── modelo de prueba V1/
├── media/                  # Videos y recursos multimedia
│   └── Brazo Robotico.mp4
├── docs/                   # Documentacion adicional
└── README.md
```

## Caracteristicas

- Deteccion de objetos en tiempo real usando YOLOv8
- Clasificacion de 2 tipos de figuras impresas en 3D: DINO y Hongo
- Comunicacion serial bidireccional con ESP32
- Control automatizado de brazo robotico
- Dataset personalizado entrenado con Roboflow

## Requisitos

### Software

```bash
# Python
- Python 3.8+
- ultralytics (YOLOv8)
- opencv-python
- pyserial
- matplotlib

# Hardware
- Arduino IDE o PlatformIO para ESP32
```

### Hardware

- ESP32
- Brazo robotico (servos)
- Camara web o camara compatible
- Cable USB para comunicacion serial
- Fuente de alimentacion para el brazo

## Instalacion

1. Clonar el repositorio:
```bash
git clone https://github.com/tu-usuario/Deteccion-y-clasificacion-robotica-YOLO-ESP32.git
cd Deteccion-y-clasificacion-robotica-YOLO-ESP32
```

2. Instalar dependencias de Python:
```bash
pip install ultralytics opencv-python pyserial matplotlib
```

3. Cargar el firmware en el ESP32:
- Abrir `hardware/Control del brazo.ino` en Arduino IDE
- Seleccionar la placa ESP32
- Configurar el puerto serial
- Cargar el sketch

## Uso

### 1. Configurar la comunicacion serial

Editar `src/Inferencia.py` para ajustar el puerto serial:

```python
ser = serial.Serial('COM4', 115200, timeout=1)  # Cambiar COM4 segun tu sistema
```

En Linux/Mac seria algo como `/dev/ttyUSB0` o `/dev/ttyACM0`

### 2. Ejecutar el sistema de deteccion

```bash
python src/Inferencia.py
```

### 3. Entrenar el modelo (opcional)

Abrir y ejecutar `src/YoloCV.ipynb` en Google Colab o Jupyter Notebook local con GPU.

## Dataset

El dataset contiene imagenes de figuras impresas en 3D con las siguientes clases:

- **DINO**: Figura de dinosaurio
- **Hongo**: Figura de hongo

Dataset disponible en Roboflow: [Deteccion de figuras impresas 3D](https://universe.roboflow.com/va-e0yqn/deteccion-de-figuras-impresas-3d-svghb/dataset/1)

**Configuracion del dataset:**
- Clases: 2 (DINO, Hongo)
- Formato: YOLO
- Licencia: CC BY 4.0

## Comunicacion Serial

El protocolo de comunicacion usa:
- Velocidad: 115200 baudios
- Formato: ASCII con terminacion `\n`
- Flujo: PC -> ESP32 -> Brazo Robotico

**Ejemplo de comando:**
```
Objeto_detectado: DINO\n
```

## Funcionamiento del Brazo Robotico

El ESP32 recibe comandos del sistema de vision y controla los servos del brazo para:
1. Posicionarse sobre el objeto detectado
2. Agarrar la pieza
3. Moverla al contenedor correspondiente
4. Liberar la pieza
5. Volver a posicion inicial

## Demo

Video demostrativo del sistema en funcionamiento: `media/Brazo Robotico.mp4`

## Arquitectura del Sistema

```
[Camara] -> [YOLOv8] -> [Inferencia.py] -> [Serial] -> [ESP32] -> [Brazo Robotico]
              |                                                         |
         [Clasificacion]                                         [Movimiento]
```

## Mejoras Futuras

- Soporte para mas clases de objetos
- Interfaz grafica de usuario
- Sistema de coordenadas para posicionamiento preciso
- Integracion con ROS (Robot Operating System)
- Deteccion de multiples objetos simultaneos
- Sistema de vision estereo para calculo de profundidad

## Contribuciones

Las contribuciones son bienvenidas. Por favor:

1. Fork el proyecto
2. Crea una rama para tu feature (`git checkout -b feature/nueva-caracteristica`)
3. Commit tus cambios (`git commit -m 'Agregar nueva caracteristica'`)
4. Push a la rama (`git push origin feature/nueva-caracteristica`)
5. Abre un Pull Request

## Licencia

Este proyecto esta bajo la Licencia MIT. Ver el archivo `LICENSE` para mas detalles.

## Autor

Desarrollado como proyecto de robotica y vision artificial.

## Contacto

Para preguntas o sugerencias, por favor abre un issue en el repositorio.

## Agradecimientos

- Ultralytics por YOLOv8
- Roboflow por las herramientas de dataset
- Comunidad de OpenCV
