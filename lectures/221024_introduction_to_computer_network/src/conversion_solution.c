#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <string.h>
// #include <arpa/inet.h>

#ifdef __APPLE__
#include "./endian.h"
#else
#include <endian.h>
#endif

typedef struct NetworkMessage {
    uint32_t i;
    uint32_t j;
} NetworkMessage_t;

int main() 
{
    uint8_t one_start = 4;
    uint16_t two_start = 12840;
    uint32_t four_start = 5463300;
    uint64_t eight_start = 7980987145;

    printf("Starting values are:        %d, %d, %d, %ld\n\n", 
        one_start, two_start, four_start, eight_start);

    // Task 1. Update these four assignments so that they are dynamically
    // converted from host-byte-order to network-byte-order (e.g. little-endian
    // to big-endian)
    uint8_t one_network = one_start;
    uint16_t two_network = htons(two_start);
    uint32_t four_network = htonl(four_start); 
    uint64_t eight_network = be64toh(eight_start);

    printf("Network values should be:   %d, %d, %d, %ld\n", 
        4, 10290, 73224960, 663072422861209600);
    printf("Network values are:         %d, %d, %d, %ld\n\n", 
        one_network, two_network, four_network, eight_network);

    // Task 2. Update these four assignments so that they are dynamically
    // converted from network-byte-order to host-byte-order (e.g. big-endian to
    // little-endian)
    uint8_t one_host = one_start;
    uint16_t two_host = le16toh(two_start);
    uint32_t four_host = le32toh(four_start); 
    uint64_t eight_host = le64toh(eight_start);

    printf("Host values should be:      %d, %d, %d, %ld\n", 
        4, 12840, 5463300, 7980987145);
    printf("Host values are:            %d, %d, %d, %ld\n\n", 
        one_host, two_host, four_host, eight_host);

    // Task 3. Hopefully by now you've noticed that the uint8_t value does not
    // get converted. Describe why this is.

    /*
        This is because when we swap between host and network. We convert from big 
        endian to little endian. Therefore, the single digit bytes stays the same.
    */

    // Task 4. In the char array below, which simulates a message read from the
    // network, the first 4 bytes should be read as one number, and the final 4
    // bytes as another. Extract these. Note that first has been *partially* 
    // implemented but you should be aware that as this is supposedly a 
    // networked message it will be network-byte-order

    char buffer[8] = {4, 24, 102, 7, 0, 89, 24, -92};

    uint32_t first = *(uint32_t*)&buffer[1]; // This is not complete
    uint32_t second = 0;

    printf("Extacted values should be:      %d, %d, \n", 68707847, 5839012);
    printf("Extacted values are:            %d, %d, \n\n", first, second);
}
