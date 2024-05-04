#include <db.h>
#include <stdio.h>

int main() {
    DB_ENV *env;
    u_int32_t env_flags = DB_CREATE | DB_INIT_MPOOL;
    // Display BerkeleyDB version information
    printf("\n\n%s\n\n", db_full_version(NULL, NULL, NULL, NULL, NULL));

    // Create a BerkeleyDB environment
    printf("Creating BerkeleyDB environment...\n");
    int ret = db_env_create(&env, 0);
    if (ret != 0) {
        // Handle error
        printf("Error creating BerkeleyDB environment: %s\n", db_strerror(ret));
        return ret;
    }

    // Set the database home directory
    printf("Setting database home directory...\n");
    ret = env->set_data_dir(env, "/Users/sidney/tmp/bdbtest/user_state");
    if (ret != 0) {
        // Handle error
        printf("Error setting database home directory: %s\n", db_strerror(ret));
        env->close(env, 0);
        return ret;
    }

    // Open the BerkeleyDB environment
    printf("Opening BerkeleyDB environment...\n");
    ret = env->open(env, NULL, env_flags, 0);
    if (ret != 0) {
        // Handle error
        printf("Error opening BerkeleyDB environment: %s\n", db_strerror(ret));
        env->close(env, 0);
        return ret;
    }

    // Close the BerkeleyDB environment
    /*printf("Closing BerkeleyDB environment...\n");
    ret = env->close(env, 0);
    if (ret != 0) {
        // Handle error
        printf("Error closing BerkeleyDB environment: %s\n", db_strerror(ret));
        return ret;
    }*/
    printf("BerkeleyDB environment closed.\n");
    return 0;
}

