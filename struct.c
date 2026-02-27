#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

struct UserProfile
{
    char username[32];
    uint32_t id;
    uint16_t x_pos;
    uint16_t y_pos;
    uint8_t level;
};

void update_profile(struct UserProfile *p)
{
    p->x_pos += 10;
    p->y_pos -= 5;
    printf("Updated %s to (%d, %d)\n", p->username, p->x_pos, p->y_pos);
}

struct TimerRegister
{
    uint32_t CONTROL;   // Offset 0x00
    uint32_t RELOAD;    // Offset 0x04
    uint32_t VALUE;     // Offset 0x08
    uint32_t INTERRUPT; // Offset 0x0C
};

void init_timer()
{
    volatile struct TimerRegister *timer = (struct TimerRegister *)0x40001000;

    timer->RELOAD = 0xFFFF;
    timer->CONTROL |= 0x01;
}

int main() {}