
# Examen Práctico: Implementación de una Lámpara de Curado UV con Control de Tiempo

## Objetivo:
Implementar un sistema que simule el funcionamiento de una lámpara de curado UV, utilizando 2 pulsadores y 3 LEDs. Los pulsadores deben permitir la configuración del tiempo de curado (entre 1 y 10 segundos). El sistema debe almacenar la configuración en la EEPROM y controlar el proceso de curado UV cuando se activen ambos pulsadores simultáneamente.

## Descripción del Sistema:
- **Pulsadores:**
  - **BTN1:** Incrementa el tiempo de curado.
  - **BTN2:** Decrementa el tiempo de curado.
  - **Ambos pulsadores simultáneamente:** Inician el proceso de curado UV con el tiempo configurado.

- **LEDs:**
  - **LED 1 (Configuración):** Se enciende durante la configuración del tiempo de curado.
  - **LED 2 (Curado en Proceso):** Se enciende cuando comienza el proceso de curado.
  - **LED 3 (Temporizador):** Parpadea cada segundo mientras el proceso de curado está activo.

## Requerimientos:
1. **Configuración de Tiempo:**
   - Usar los pulsadores **BTN1** y **BTN2** para ajustar el tiempo de curado, con un mínimo de 1 segundo y un máximo de 10 segundos.
   - **BTN1:** Incrementa el tiempo.
   - **BTN2:** Decrementa el tiempo.
   - El tiempo configurado debe almacenarse en la **EEPROM** para que se mantenga en la próxima ejecución del sistema.

2. **Proceso de Curado:**
   - Presionar ambos pulsadores simultáneamente iniciará el proceso de curado UV.
   - Cuando comience el curado, se deben activar los siguientes comportamientos:
     - El **LED 1** se apaga, y el **LED 2** se enciende.
     - El **LED 3** parpadeará cada segundo mientras el temporizador cuenta hacia atrás.
   - Cuando el tiempo de curado termine, los **LEDs 2 y 3** se apagarán y el **LED 1** se volverá a encender.

3. **Monitoreo en serial:**
   - Mostrar en el **Monitor Serial** el tiempo de curado configurado durante la configuración.
   - Durante el curado, se debe imprimir la cuenta regresiva del tiempo restante en segundos.
   - Al finalizar el proceso de curado, se debe mostrar un mensaje de **"CURADO COMPLETADO"**.

## Procedimiento:
1. **Configuración Inicial:**
   - Al iniciar el sistema, el **LED 1** debe encenderse y los pulsadores deben permitir ajustar el tiempo de curado.
   - El tiempo se debe mostrar en el **Monitor Serial**.
   - La configuración se almacena automáticamente en la EEPROM.

2. **Inicio del Proceso de Curado:**
   - Presionar ambos pulsadores a la vez debe comenzar el curado UV.
   - Durante el curado, el **LED 3** debe parpadear cada segundo mientras el temporizador cuenta hacia atrás.
   - Cuando el proceso de curado termine, todos los LEDs se apagarán excepto el **LED 1**, que indicará que el sistema vuelve a estar en modo de configuración.

3. **Evaluación:**
   - El código debe implementar el control de los LEDs y los pulsadores con **interrupciones** y **antirrebote utilizando `millis()`**.
   - El sistema debe almacenar el tiempo de curado en la **EEPROM** y recuperarlo al iniciar el sistema.
   - El **Monitor Serial** debe mostrar correctamente el tiempo configurado y el progreso del curado.

## Pseudocódigo:
1. Inicializar los **LEDs** y los **pulsadores**.
2. Leer el tiempo de curado desde la EEPROM.
3. Permitir la configuración del tiempo mediante los pulsadores.
4. Iniciar el curado UV cuando ambos pulsadores se presionen simultáneamente.
5. Parpadear el **LED 3** cada segundo durante el curado.
6. Al finalizar el curado, apagar los LEDs 2 y 3 y volver al modo de configuración.

## Ejemplo de comportamiento:

- **Configuración inicial:**
  - Al encender el sistema, el **LED 1** está encendido.
  - Presionar **BTN1** aumenta el tiempo de curado, y presionar **BTN2** lo reduce.
  - El tiempo configurado se muestra en el **Monitor Serial**.
  
- **Proceso de curado:**
  - Presionar ambos pulsadores simultáneamente inicia el curado UV. El **LED 1** se apaga, el **LED 2** se enciende y el **LED 3** parpadea.
  - El **Monitor Serial** muestra una cuenta regresiva.
  
- **Finalización del curado:**
  - Una vez que el tiempo configurado termina, se apagan los **LEDs 2 y 3**, y el **LED 1** se vuelve a encender indicando que el sistema vuelve al modo de configuración.
