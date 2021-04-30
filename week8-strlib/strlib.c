int strlength(const char *str) {
    int count = 0;
    while (*(str++)) {
        count++;
    }
    return count;
}

int strfind(const char *str, const char *sub) {
    const char *pstr = str;
    const char *psub = sub;
    int match = -1;

    if (!*psub) {
        return 0;
    }

    while (*pstr) {
        if (*pstr == *psub++) {
            if (match == -1) {
                match = (int) (pstr - str);
            }
            if (!*psub) {
                return match;
            }
        } else {
            psub = sub;
            match = -1;
        }
        pstr++;
    }

    return -1;
}

int strequal(const char *str1, const char *str2) {
    while (*str1++ == *str2++) {
        if (!*str1 && !*str2) {
            return 1;
        }
    }
    return 0;
}

void strcopyn(const char *str, char *buf, int buflen) {
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
    while (*str == chr) str++;

    const char *end;
    end = str + strlength(str) - 1;
    while (*end == chr) end--;
    end++;

    while (str < end) {
        *buf++ = *str++;
    }

    *buf = '\0';
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
