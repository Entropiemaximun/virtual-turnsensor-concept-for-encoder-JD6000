# virtual-turnsensor-concept-for-encoder-JD6000

https://youtube.com/shorts/vLLpzsV9wfQ

AOG virtual-turnsensor concept  for encoder  JD6000 series  R  &amp; M

  JD  encoder turn sensor generate wave modification  with similar frequency  in voltmeter  we can see  some  voltage  mofdification   (  for  6R 6M)

 on sterring  colon  ther eis  turn sensor   with connector  4  wire 

  we need  to use   green (  or  yellow )   and  brown 

-----------------------------------

  for   AIO   with teensy  (  v4  during this  test )    -------------BricBric code    with Buched  Debug help 
  
  update  to  use A14  to    make analisis  of the wave  of JD  turn sensor  and apply  virtual turn sensor concept
  /!\  make  sure  that   AIO  input  with connected  with  voltage divider   with 2 resistance  10~50K 
  /!\  faire attention que la  carte  AIO  soit connecteé avec un pont de resistance (10~50K) pour faire un diviseur de tension  


JD        Green  wire (fils vert )  --------
                                            |
                                            §    (10-50KOhm)
                                            |
                                            ----------------------A14  AIO
                                            |
                                            §    (10-50KOhm)
                                            |
JD        Brown  wire (fils marron )  -------------------------- GND   AIO

![image](https://github.com/Entropiemaximun/virtual-turnsensor-concept-for-encoder-JD6000/assets/88970536/734c824a-234e-435a-8316-813708f333f6)

-----------------------------


  Alternative  with   Nano to make analysis  and  connect  to remote of  PCB 


  
JD        Red  wire (fils rouge )  --------------------------  +5V Nano
JD        Green  wire (fils vert )  -------------------------  A1  Nano 
                                                               D13  Nano  ---------------- Remote  Board
JD        Brown  wire (fils marron )  ------------------------  GND  Nano ---------------- GND Board
  


--------------------------------

 Code concept 

 base  like  virtual sensor  ( https://github.com/Entropiemaximun/AOG-electric-motor-release-by-virtual-Turn-sensor)
  check if  there is  some  significant  modification to  sum   it in case   of  quantity    of modification  will be exceed  turn sensor value   he  will consider to  stop autosteering 

   the  JD  6000 R   or  M (  model 2023 2024 )   are equieped   with  some  kind  of  encoder  with  wave  modification )   that  look an  PWM   signal  so the analisis  need to  be  on the shape  of  the  HIGH   wave  instead frequency 



   
