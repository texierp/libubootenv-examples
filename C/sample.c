/*
 * (C) Copyright 2020
 * Pierre-Jean Texier, Koncepto, pjtexier@koncepto.io.
 *
 * SPDX-License-Identifier:     LGPL-2.1-or-later
 */

#include <stdio.h>
#include <stdlib.h>
#include <libuboot.h>

#define LIBUBOOTENV_DEFAULTENV "/etc/u-boot-initial-env"
#define LIBUBOOTENV_FWENV "/etc/fw_env.config"

int main (int argc, char **argv)
{
	int ret = 0;
	struct uboot_ctx *ctx;
	const char *envval;

	if (libuboot_initialize(&ctx, NULL) < 0) {
		fprintf(stderr, "Cannot initialize environment\n");
		exit(1);
	}
	
	if (libuboot_read_config(ctx, LIBUBOOTENV_FWENV) < 0) {
		printf("Configuration file %s wrong or corrupted\n", LIBUBOOTENV_FWENV);
		exit(-1);
	}
	
	if (libuboot_open(ctx) < 0) {
		printf("Cannot read environment, using default\n");
		libuboot_load_file(ctx, LIBUBOOTENV_DEFAULTENV);
	}

	// setenv
	libuboot_set_env(ctx, "foo", "bar");
	ret = libuboot_env_store(ctx);
	if (ret != 0) {
		printf("libuboot_env_store() error\n");
	}
	
	// printenv
	envval = libuboot_get_env(ctx, "foo");
	fprintf(stdout, "%s\n", envval ? envval : "");

	libuboot_close(ctx);
	libuboot_exit(ctx);
	
	return 0;
}
