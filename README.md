# Tank Level PID Control / Controle PID para nível de tanque

PT-BR:

O trabalho foi desenvolvido na disciplina de Controle Digital onde tivemos que realizar o controle de nível do tanque inferior da plataforma de simulação Quaser.

![image](https://github.com/lucasvinasl/tank_level_pid_control/assets/74206824/2ad62a77-4152-4084-beee-3e91ecd96b5d)

Foi realizada a calibração do tanque para encontrarmos as equações de regressão que descreveriam o comportamento tanto do tanque superior quanto inferior, para isso foi realizado testes manuais e os dados foram colocados no Excel.
A partir do código em python foi possível realizar a regressão dos pontos e extrair ambas as equações para os tanques.
Utilizando python também foi possível realizar o plot dos gráficos das variáveis de processo, manipuladas e setpoints.
De posse das equações foi possível realizar a sintonia do controlador PID utilizando código Arduino.

Foi realizado o controle convencional e posteriormente o controle escalonado do processo que consistia em dividir o tanque em diferentes regiões e implementar diferentes PID afim de melhorar os indicadores de processo.

EN:
The work was developed in the Digital Control discipline where we had to control the level of the lower tank of the Quemer simulation platform.

The tank was calibrated to find the regression equations that would describe the behavior of both the upper and lower tanks. For this, manual tests were carried out and the data was entered into Excel.
Using the Python code, it was possible to perform point regression and extract both equations for the tanks.
Using Python, it was also possible to plot graphs of process variables, manipulated variables and setpoints.
With the equations in hand, it was possible to tune the PID controller using Arduino code.

Conventional control was carried out and later staged control of the process, which consisted of dividing the tank into different regions and implementing different PIDs in order to improve process indicators.


Regressão do tanque inferior e superior  /  Lower and upper tank regression
![image](https://github.com/lucasvinasl/tank_level_pid_control/assets/74206824/b8b240dd-6d90-4ac8-b3e9-3151d1740410)

![image](https://github.com/lucasvinasl/tank_level_pid_control/assets/74206824/a93d41c8-aef9-42ba-9553-86acc7ec7986)

Gráfico do Setpoint, Variável de Processo e Variável Manipulada do controle convencional / Graphic of Setpoint, Process Variable and Manipulated Variable of conventional control

![image](https://github.com/lucasvinasl/tank_level_pid_control/assets/74206824/aa437974-66f5-4c20-b7b9-5b734e138c01)
![image](https://github.com/lucasvinasl/tank_level_pid_control/assets/74206824/ccbba2c3-4d12-40c3-974c-6e3776653055)

Gráfico do Setpoint, Variável de Processo e Variável Manipulada do controle escalonado / Graph of the Setpoint, Process Variable and Manipulated Variable of the scaled control

![image](https://github.com/lucasvinasl/tank_level_pid_control/assets/74206824/dece6c8a-afd2-418c-bded-cb9cb007394d)
![image](https://github.com/lucasvinasl/tank_level_pid_control/assets/74206824/09d22bbe-c8da-4821-9e1b-aedc2df1efe8)


