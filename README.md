# FiltLong
# Language: C++
# Input: TXT
# Output: DIR
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies: filtlong 0.2.0

PluMA plugin to run FiltLong, a filter for long reads.

The plugin takes as input a TXT file.
The first line of the TXT file is the input FASTQ file.

The rest are  tab-delimited keyword-value parameters.

Keywords:
min_length: Minimum length
mean_q_weight: Quality score
keep_percent: Threshold percentage
target_bases: Number of target bases

Filtered sequences will be sent to the user-specified output directory
