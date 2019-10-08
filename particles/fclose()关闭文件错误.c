if (fclose(fp) != 0)
    fprintf(stderr, "Error closing file\n");

//使用stderr指针把错误消息发送至标准错误，显示在显示器上