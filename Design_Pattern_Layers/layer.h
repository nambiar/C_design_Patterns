#ifndef LAYER_H
#define LAYER_H

typedef void (*func_ptr)(void);
typedef enum protocol_layers
{
	LAYER_0,
	LAYER_1,
	LAYER_2,
	LAYER_3
	
}protocol_layers;

typedef struct protocol_layers_context
{
	func_ptr ptr_protocol_layers[4];
	
};

#endif