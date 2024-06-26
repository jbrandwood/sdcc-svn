/*
   20071030-1.c from the execute part of the gcc torture suite.
 */

#include <testfwk.h>

#ifdef __SDCC
#pragma std_c99
#pragma disable_warning 93
#endif

#include <string.h>

/* PR target/11044 */
/* Originator: Tim McGrath <misty-@charter.net> */
/* Testcase contributed by Eric Botcazou <ebotcazou@libertysurf.fr> */

/* Testcase copied from gcc.target/i386/loop-3.c */

#if !defined(__SDCC_pdk14) && !defined(__SDCC_pdk15) // Lack of memory
typedef struct
{
        unsigned char colormod;
} entity_state_t;

typedef struct
{
        int num_entities;
        entity_state_t *entities;
} packet_entities_t;

typedef struct
{
        double senttime;
        float ping_time;
        packet_entities_t entities;
} client_frame_t;

typedef enum
{
        cs_free,
        cs_server,
        cs_zombie,
        cs_connected,
        cs_spawned
} sv_client_state_t;

typedef struct client_s
{
        sv_client_state_t state;
        int ping;
        client_frame_t frames[64];
} client_t;

int CalcPing (client_t *cl)
{
        float ping;
        int count, i;
        register client_frame_t *frame;

        if (cl->state == cs_server)
                return cl->ping;
        ping = 0;
        count = 0;
        for (frame = cl->frames, i = 0; i < 64; i++, frame++) {
                if (frame->ping_time > 0) {
                        ping += frame->ping_time;
                        count++;
                }
        }
        if (!count)
                return 9999;
        ping /= count;

        return ping * 1000;
}
#endif

void testTortureExecute(void)
{
#if !defined(__SDCC_mcs51) && !defined(__SDCC_pdk14) && !defined(__SDCC_pdk15) && !( (defined (__SDCC_mos6502) || defined(__SDCC_mos65c02 )) && defined(__SDCC_STACK_AUTO) )// Lack of memory
   client_t cl;

   memset(&cl, 0, sizeof(cl));

   cl.frames[0].ping_time = 1.0f;

   if (CalcPing(&cl) != 1000)
     ASSERT (0);

   return;
#endif
}
