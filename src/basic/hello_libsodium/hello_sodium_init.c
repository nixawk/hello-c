#include <sodium.h>

/*

sodium_init() initializes the library and should be called before any other
function provided by Sodium. It is safe to call this function more than once
and from different threads -- subsequent calls won't have any effects.

After this function returns, all of the other function privided by Sodium will
be thread-safe.

sodium_init() doesn't perform any memory allocations. However, on Unix systems,
it may open /dev/urandom and keep the descriptor open, so that the device
remains accessible after a chroot() call.

Multiple calls to sodium_init() do not cause additoinal descriptors to be opened.

sodium_init() returns 0 on success, -1 on failure, and 1 if the library had
already been initialized.

Before returning, the function ensures that the system's random number generator
has been properly seeded.

*/

int main(void)
{
	if (sodium_init() < 0) {
		exit(EXIT_FAILURE);
	}

	return 0;
}

// reference
// https://download.libsodium.org/doc/usage
