#include <RH_ASK.h>
#include <Servo.h>

// Инициализация на 433MHz приемник
RH_ASK driver;

// Дефиниране на серво моторите
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

void setup()
{
    Serial.begin(9600); // Стартиране на серийната комуникация
    if (!driver.init())
    {
        Serial.println("RH_ASK инициализацията се провали!");
        while (1); // Спиране при неуспех
    }

    // Свързване на серво моторите към съответните пинове
    servo1.attach(2);
    servo2.attach(3);
    servo3.attach(4);
    servo4.attach(5);
    servo5.attach(6);
}

void loop()
{
    uint8_t buf[32];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) // Проверка за получени данни
    {
        buf[buflen] = '\0'; // Добавяне на терминатор за низ
        int flex1, flex2, flex3, flex4, flex5;
        sscanf((char *)buf, "%d,%d,%d,%d,%d", &flex1, &flex2, &flex3, &flex4, &flex5);

        // Показване на получените стойности в серийния монитор
      Serial.print("Получени стойности: ");
      Serial.print(flex1); Serial.print(", ");
      Serial.print(flex2); Serial.print(", ");
      Serial.print(flex3); Serial.print(", ");
      Serial.print(flex4); Serial.print(", ");
      Serial.println(flex5);


        // Мапване и ограничаване на стойностите за всеки сервомотор
        int servo1_pos = map(flex1, 850, 1018, 0, 150);
        servo1_pos = constrain(servo1_pos, 0, 150);
        servo1.write(servo1_pos);

        int servo2_pos = map(flex2, 1000, 820, 15, 180);
        servo2_pos = constrain(servo2_pos, 15, 180);
        servo2.write(servo2_pos);

        int servo3_pos = map(flex3, 800, 960, 180, 20);
        servo3_pos = constrain(servo3_pos, 20, 180);
        servo3.write(servo3_pos);

        int servo4_pos = map(flex4, 810, 961, 180, 0);
        servo4_pos = constrain(servo4_pos, 0, 180);
        servo4.write(servo4_pos);

        int servo5_pos = map(flex5, 862, 1000, 0, 90);
        servo5_pos = constrain(servo5_pos, 0, 90);
        servo5.write(servo5_pos);
    }
}
