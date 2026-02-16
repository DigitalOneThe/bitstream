## BitStream

Examples:
Writing array and reading...
```
BitStream<int*> bitStream;
 
int* arrayInts = new int[30];
 
arrayInts[0] = 1;
arrayInts[1] = 50;
 
bitStream.Write(&arrayInts, sizeof(int));
 
const void* data = bitStream.GetData();
 
BitStream<int*> readStream((int* const*)data, bitStream.GetLenght());
int* readInts = new int[30];
readStream.Read(&readInts, sizeof(int));
 
printf("readInts[0]: %d\n", readInts[0]);
printf("readInts[1]: %d\n", readInts[1]);

// Default writing and reading...

BitStream<int> bitStream;
 
int a = 50;
bitStream.Write(&a, sizeof(int));
 
const void* data = bitStream.GetData();
BitStream<int> readStream((int* const)data, bitStream.GetLenght());
 
int aRead = 0;
readStream.Read(&aRead, sizeof(int));
 
printf("aRead: %i\n", aRead);
```
