char* simplifyPath(char* path) {
    if (path == NULL || *path == '\0') {
        return "/";
    }

    int len = strlen(path);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int resultIndex = 0;
    char* token = strtok(path, "/");
    
    while (token != NULL) {
        if (strcmp(token, "..") == 0) {
            if (resultIndex > 0) {
                while (resultIndex > 0 && result[resultIndex - 1] != '/') {
                    resultIndex--;
                }
                if (resultIndex > 0) {
                    resultIndex--;
                }
            }
        } else if (strcmp(token, ".") != 0 && strcmp(token, "") != 0) {
            result[resultIndex++] = '/';
            strcpy(result + resultIndex, token);
            resultIndex += strlen(token);
        }
        token = strtok(NULL, "/");
    }
    if (resultIndex == 0) {
        result[resultIndex++] = '/';
    }
    result[resultIndex] = '\0';

    return result;
}
    
