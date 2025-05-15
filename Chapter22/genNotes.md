# Chapter 22
# Working With Files

"We have seen how to get data to and from the console via output and input streams. The next step in our exploration of input and output streams is to be able to access a persistent storage mechanism, one where we can save our data, exit the program, and then use it later. "

## Understanding Basic File Concepts

Up to now, our data input and outputs have moved in and out of our C programs via streams through scanf, printf, or other related IO functions. But most data exists on computers in files.

## Revisting File Streams

A stream is the means of transferring data, specifically bytes between any device and a program.

Streams are device oriented.

Devices include a keyboard, screen...

These are associated with the stdin and stdout predefined streams.

A file is an abstract data storage device.

Other devices include SSDs, HDDs, CDs, DVDs, ...

...

C supports two types of streams - a text stream and a binary stream. A text stream consists of lines of bytes, primarily printable characters in the range 32 to 126: These are readable to us humans.

The added constraint is that each line of bytes should end with '\n'

Text streams are sometimes called sequential access streams because each line of text can vary in length, so it would be nearly impossible to position the file at the beginning of any one line with a simple offset. So the file must be read sequentially from the beginning to end to be properly interpreted.

A binary stream is byte oriented and is only intelligible to other programs. We have been using both of these stream types from the very start of the book!!!

We generated text streams with scanf, printf and other functions.

Binary streams were used when we created executable files and ran them on the console.

A binary stream can either be a collection of binary data like an executable file, or it can be a collection of fixed length records or blocks of data, in which case it is sometimes called a random-access stream.

A random-access stream is very much likee an array of structures, where an offset to the beginning of any structure can be a simple calculation of the x record number and the size of the record. Random-access files are common in transaction-oriented processing systems, such as banking systems, airline reservation systems, and point of sale systems.

"So, while there are various types of files, files and streams are closely related. Through the creation of a stream, data moves to and from a file and is persistently stored for later use"

## Understanding the Properties of FILE Streams

We encountered FILE structure in CH21, this structure has information needed to control a stream!!!! It has the following


• A current position indicator: This is relevant if the device has a beginning and an end, such as a file. 

• An End-of-File (EOF) indicator: To show whether we are at the end of the file or not.

• An error indicator: To show whether an error occurred.

• A data buffer: When in buffer mode, data is temporarily stored here.

• A buffer state: Indicates what kind of buffering is in use.

• I/O mode: Indicates whether this is input, output, or an update stream. An update stream performs both input and output; it requires advanced file manipulations to use properly.

__• Binary or text mode: To show whether the stream  is a text stream or a binary stream.__

• An I/O device identifier: A platform-specific identifier of an associated I/O device.

We never access these fields directly.

Instead each field, if it is accessible, has an associated file function for instance to check the EOF, call the feof fcn.

Some of these properties are set when the file stream is opened and others are updated as the file stream is manipualted.

A file stream that is declared as FILE* is also known as a file descriptor.

## Opening and Closing a File

TO create a file stream, a filename and an IO mode has to be specified.

There are THREE general IO modes that are specified with character strings:

- r: Opens an existing file for reading. If it fails, the filename does not exist!

- w: Opens a file for writing. If the file exists, existing data is lost; otherwise, the file is created

- a: Opens a file for appending. If the file exists, writing commences at the end of the file; otherwise, the file is created

"These are all one-way modes – that is, a file opened for reading with r CAN ONLY BE READ; it cannot be updated. Two-way modes exist by appending + to each of the preceding modes – for example, r+,  w+, and a+. When files are opened for reading and writing, care must be exercised to re-position the current file position so as not to inadvertently overwrite existing data. We will look at the file reposition functions in the next section."

To open a binary stream, b can be appended either after the first character or at the end of the string. The following are teh possible binary access modes:

One-way modes: rb, wb, and ab

Two-way Modes: r+b, w+b, a+b, rb+, wb+, and ab+

Note, some systems ignore the b specifer; in those cases it is provided for backward compatibility

----------

A stream can be manipulated with the following functions!

fopen: Using an absolute or relative filename and mode, this creates/opens a stream

freopen: This closes the given stream and reopens it using the new filename

fclose: Closes the stream

fflush: For output or update streams, this flushes any content in the buffer to the file/device

Note fflush is only intended for the output stream buffer.

fopen will fail if the user does not have permission to read or write the file. It will also fail if a file opened for reading only does not exists

It is a good idea to always close files before exiting a program.

It is also good practice to flush the buffers of output files before clsing them.

## Understanding File Operations for Each Type of Stream

We have already seen most of the functions that are useful for text streams. They are as follows:

• fprintf(): Writes formatted text to the output stream

• fscanf(): Reads and interprets formatted text from the input stream

• fputs(): Writes an unformatted line to the output stream

• fgets(): Reads an unformatted line from the input stream

There are also some single-character functions that we have come across:

• fgetc(): Reads a single character from the input stream

• fputc(): Writes a single character to the output stream

• ungetc(): Puts a single character back into the input stream

There is a set of functions intended specifically for record- or block-oriented file manipulations. These are as follows:

• fread(): Reads a block of data of a specified size from a file

• fwrite(): Writes a block of data of a specified size to a file

• ftell() or fgetpos(): Gets the current file position

• fseek() or fsetpos(): Moves the current file position to a specified position

In block-oriented file processing, whole records are read at once. These are typically read into a structure. They may also be read into a buffer and then parsed for their individual parts.

Finally, there are some common file stream functions, as follows:

• rewind(): Moves the current position to the beginning of the file

• remove(): Deletes a file

• rename(): Renames a file

With these functions, we can create programs to manipulate files in any number of ways. C doesn't impose a structure on the content of a file. That is left up to the program and the type of data that is to be preserved in the file. These functions enable a wide variety of ways to create, modify, and delete not only the content of files but also the files themselves.

## Introducing the Filesystem Essentials

A filesystem is a component of an OS that controls how files are stored and retrieved.

There are many kinds of filesystems...

## Getting Acquainted With the Filesystem

We can think of the filesystem as the interface between the actual storage medium and our program.

## Understanding a File Path

A file path can either be an absolute file path or a relative.

An absolute file path, the base of the file hierarchy is specified, along with the name of each directory and subdirectory to the final directory where the filename exists.

A relative file path, only the portions of the path relative to the current program location are required.

Each layer in the hierarchy can be separated bya forward slash (/) in C

Also, the current working directory, regardless of path, is identified by a dot (.)

Furthermore, if the current directory has a dot, then the parent of this directory or whatever the layer is when we go up one level in the heirarchy can be specified by two dots (..)

"Default path attributes apply if no path attributes are given – for instance, if there is no path, the current directory location is the default path.

In our example programs, we will assume that the data files are in the same directory as the executable program. This is a simplified assumption. Very often, paths to data files are stored in a file with the . init or .config extension, which is read and processed when the program starts."

## Understanding a filename

A file extension consists of one or more characters with a separating dot (.) between it and the name. The combination of the name and extension must be unique within a directory.

## Opening Files for Reading and Writing

open_close_string.c program

The next two lines set the file path ("./") and filenames ("input.data" and "output.data") for the files we will soon try to open

## Getting Filenames from Within a Program

open_close_fgetstr.c

