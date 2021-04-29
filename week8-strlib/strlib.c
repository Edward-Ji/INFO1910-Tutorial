#include <stdio.h>

int strlength(const char *str) {
    unsigned int count = 0;
    while (str[count]) {
        count++;
    }
    return count;
}

int strinstr(const char *str, const char *sub) {
    int i = 0;
    int j = 0;
    int match = -1;

    while (str[i]) {
        if (str[i] == sub[j]) {
            if (match == -1) {
                match = i;
            }
            j++;
            if (!sub[j]) {
                return match;
            }
        } else {
            j = 0;
            match = -1;
        }
        i++;
    }

    return i?0:-1;
}

int streqstr(const char *str1, const char *str2) {
    int i = 0;
    int j = 0;
    while (str1[i] && str2[j]) {
        if (str1[i++] != str2[j++]) {
            return 0;
        }
    }
    return 1;
}

void strcpstr(const char *str, char *buf, int buflen) {
    int i;
    for (i = 0; i < buflen - 1; i++) {
        if (!str[i]) {
            break;
        }
        buf[i] = str[i];
    }
    buf[i] = '\0';
}

void strstrip(const char *str, char *buf, char chr) {
    int i = 0, j = 0;
    while (str[i++] == chr);
    i--;
    while(str[i]) {
        buf[j++] = str[i++];
        if (str[i] == chr) {
            int k = i;
            while (str[i++] == chr);
            if (str[i]) {
                i = k;
            }
        }
    }
    buf[j] = '\0';
}

int strsplit(const char *str, char **arr, char sep) {
    int i = 0, j = 0;
    while (str[i]) {
        int k = 0;
        while (str[i] != sep) {
            arr[j][k++] = str[i++];
            if (!str[i]) {
                i--;
                break;
            }
        }
        arr[j++][k] = '\0';
        i++;
    }
    return j;
}

void strjoin(char * const *arr, char *str, int nstr, char sep) {
    int i = 0;
    for (int j = 0; j < nstr; j++) {
        int k = 0;
        while (arr[j][k]) {
            str[i++] = arr[j][k++];
        }
        str[i++] = sep;
    }
}
