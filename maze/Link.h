#pragma once

enum class Color {
    RED,
    GREEN,
    BLUE
};

enum class Transport {
    HORSE,
    CABLECAR,
    TROLLY,
    BUS
};


struct Link {

    Link(Color color, Transport transport) {
        this->color = color;
        this->transport = transport;
    }

    Link() {
        //do nothing
    }

    Color color;
    Transport transport;
};