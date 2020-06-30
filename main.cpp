#include "mbed.h"

#include "bbcar.h"


Ticker servo_ticker;

Ticker encoder_ticker;

PwmOut pin8(D8), pin9(D9);

DigitalIn pin3(D3);

DigitalInOut pin10(D10);

BBCar car(pin8, pin9, servo_ticker);


int main() {

    parallax_encoder encoder0(pin3, encoder_ticker);

    parallax_ping  ping1(pin10);

    encoder0.reset();

    car.goStraight(100);

    while(encoder0.get_cm()<130) wait_ms(50);

    car.stop();

    wait(2);

    car.turn(100,0.3);

    encoder0.reset();

    while(encoder0.get_cm()<12) wait_ms(50);

    car.stop();

    encoder0.reset();

    car.goStraight(100);

    while(encoder0.get_cm()<70) wait_ms(50);

    car.stop();

    car.turn(-100,0.3);

    encoder0.reset();

    while(encoder0.get_cm()<15) wait_ms(50);

    car.stop();

    encoder0.reset();

    car.goStraight(-100);

    while(encoder0.get_cm()<70) wait_ms(50);

    car.stop();

    wait(2);

    encoder0.reset();

    car.goStraight(100);

    while(encoder0.get_cm()<70) wait_ms(50);

    car.stop();

    car.turn(100,-0.3);

    encoder0.reset();

    while(encoder0.get_cm()<25) wait_ms(50);

    car.stop();

    encoder0.reset();

    car.goStraight(100);

    while(encoder0.get_cm()<70) wait_ms(50);

    car.stop();

    car.turn(100,-0.3);

    encoder0.reset();

    while(encoder0.get_cm()<25) wait_ms(50);

    car.stop();

    encoder0.reset();

    car.goStraight(100);

    while(encoder0.get_cm()<120) wait_ms(50);

    car.stop();

}
