#ifdef NDEBUG
#undef NDEBUG
#endif

#include <strings.h>
#include <assert.h>

int main()
{
    assert(bcmp("hello", "hello", 5) == 0);
    assert(bcmp("hello", "world", 5) != 0);
    assert(bcmp("world", "hello", 5) != 0);

    char buffer[6];
    bcopy("hello", buffer, 5);
    assert(bcmp("hello", buffer, 5) == 0);
    assert(bcmp(buffer, "hello", 5) == 0);
    assert(bcmp("world", buffer, 5) != 0);
    assert(bcmp(buffer, "world", 5) != 0);
    bcopy("world", buffer, 5);
    assert(bcmp("hello", buffer, 5) != 0);
    assert(bcmp(buffer, "hello", 5) != 0);
    assert(bcmp("world", buffer, 5) == 0);
    assert(bcmp(buffer, "world", 5) == 0);

    bzero(buffer, 5);
    assert(bcmp(buffer, "\0\0\0\0\0", 5) == 0);
    assert(bcmp("\0\0\0\0\0", buffer, 5) == 0);
    assert(bcmp("hello", buffer, 5) != 0);
    assert(bcmp(buffer, "hello", 5) != 0);

    explicit_bzero(buffer, 5);
    assert(bcmp(buffer, "\0\0\0\0\0", 5) == 0);
    assert(bcmp("\0\0\0\0\0", buffer, 5) == 0);
    assert(bcmp("hello", buffer, 5) != 0);
    assert(bcmp(buffer, "hello", 5) != 0);

    char hello[] = "hello";
    char world[] = "world";
    assert(index(hello, 'e') == hello + 1);
    assert(rindex(hello, 'e') == hello + 1);
    assert(index(hello, 'l') == hello + 2);
    assert(rindex(hello, 'l') == hello + 3);
    assert(index(hello, 'w') == NULL);
    assert(rindex(hello, 'w') == NULL);

    assert(index(world, 'e') == NULL);
    assert(rindex(world, 'e') == NULL);
    assert(index(world, 'l') == world + 3);
    assert(rindex(world, 'l') == world + 3);
    assert(index(world, 'w') == world);
    assert(rindex(world, 'w') == world);

    assert(ffs(0) == 0);
    assert(ffs(1) == 1);
    assert(ffs(2) == 2);
    assert(ffs(3) == 1);
    assert(ffs(4) == 3);
    assert(ffs(5) == 1);

    assert(ffsl(0) == 0);
    assert(ffsl(1) == 1);
    assert(ffsl(2) == 2);
    assert(ffsl(3) == 1);
    assert(ffsl(4) == 3);
    assert(ffsl(5) == 1);

    assert(ffsll(0) == 0);
    assert(ffsll(1) == 1);
    assert(ffsll(2) == 2);
    assert(ffsll(3) == 1);
    assert(ffsll(4) == 3);
    assert(ffsll(5) == 1);

    assert(strcasecmp("hello", "hello") == 0);
    assert(strcasecmp("HELLO", "hello") == 0);
    assert(strcasecmp("HELLO", "world") != 0);
    assert(strcasecmp("hello", "hello2") != 0);
    assert(strcasecmp("hello2", "hello") != 0);

    assert(strncasecmp("hello", "hello", 5) == 0);
    assert(strncasecmp("HELLO", "hello", 5) == 0);
    assert(strncasecmp("HELLO", "world", 5) != 0);
    assert(strncasecmp("hello", "hello2", 5) == 0);
    assert(strncasecmp("hello2", "hello", 5) == 0);
}
