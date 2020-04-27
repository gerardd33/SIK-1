#ifndef INPUT_DATA_H_
#define INPUT_DATA_H_

// Resource path is stored without the initial '/'.
// We have to add it before the request.
typedef struct input_data {
  char* connection_address;
  char* connection_port;
  char* cookie_file_name;
  char* host_name;
  char* resource_path;
} input_data_t;

#endif  // INPUT_DATA_H_
