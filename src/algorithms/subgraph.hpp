#pragma once

#include "../handle.hpp"
//#include "../subgraph.hpp"
#include "../types.hpp"
#include "shortest_cycle.hpp"
#include "eades_algorithm.hpp"
#include "strongly_connected_components.hpp"
#include "is_single_stranded.hpp"
#include <unordered_map>

namespace vg {
namespace algorithms {

using namespace std;

/// expand the subgraph iteratively for this many steps
void expand_subgraph_by_steps(const HandleGraph& source, MutableHandleGraph& subgraph, uint64_t steps, bool forward_only = false);

/// expand the subgraph iteratively until its node count is at least node_count
void expand_subgraph_to_node_count(const HandleGraph& source, MutableHandleGraph& subgraph, uint64_t node_count, bool forward_only = false);

/// expand the subgraph iteratively to include at least length new sequence
void expand_subgraph_by_length(const HandleGraph& source, MutableHandleGraph& subgraph, uint64_t length, bool forward_only = false);

/// expand the subgraph iterativel until its total sequence length is greater than length
void expand_subgraph_to_length(const HandleGraph& source, MutableHandleGraph& subgraph, uint64_t length, bool forward_only = false);

/// add subpaths to the subgraph, providing a concatenation of subpaths that are discontiguous over the subgraph
/// based on their order in the path position index provided by the source graph
/// will clear any path found in both graphs before writing the new steps into it
void add_subpaths_to_subgraph(const PathPositionHandleGraph& source, MutablePathHandleGraph& subgraph);

}
}