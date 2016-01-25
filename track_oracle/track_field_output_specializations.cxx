/*ckwg +5
 * Copyright 2012-2016 by Kitware, Inc. All Rights Reserved. Please refer to
 * KITWARE_LICENSE.TXT for licensing information, or contact General Counsel,
 * Kitware, Inc., 28 Corporate Drive, Clifton Park, NY 12065.
 */

#include "track_field_output_specializations.h"

#include <stdexcept>
#include <utility>
#include <iostream>
#include <vector>
#include <sstream>

using std::ostream;
using std::pair;
using std::runtime_error;
using std::set;
using std::string;
using std::vector;

namespace kwiver {
namespace kwant {

// specialization for e.g. frame lists
template< >
ostream& operator<<( ostream& os,
                         const track_field< frame_handle_list_type >& f ) {
  os << " (" << f.field_handle << ") "
     << f.name;
  try
  {
    frame_handle_list_type frame_list = f();
    os << ": frames are: [ ";
    for (unsigned i=0; i<frame_list.size(); ++i) {
      os << frame_list[i].row << " ";
    }
    os << "]";
  }
  catch (runtime_error const& )
  {
    os << " (no row set)";
  }
  return os;
}

template< >
ostream& operator<<( ostream& os,
                         const track_field< track_handle_list_type >& f ) {
  os << " (" << f.field_handle << ") "
     << f.name;
  try
  {
    track_handle_list_type track_list = f();
    os << ": tracks are: [ ";
    for (unsigned i=0; i<track_list.size(); ++i) {
      os << track_list[i].row << " ";
    }
    os << "]";
  }
  catch (runtime_error const& )
  {
    os << " (no row set)";
  }
  return os;
}

template< >
ostream& operator<<( ostream& os,
                         const track_field< vector< unsigned int> >& f ) {
  os << " (" << f.field_handle << ") " << f.name;
  try
  {
    vector<unsigned> d = f();
    os << "[size=" << d.size() << "] ";
    for (unsigned i=0; i<d.size(); ++i)
    {
      os << d[i] << " ";
    }
  }
  catch (runtime_error const& )
  {
    os << " (no row set)";
  }
  return os;
}

template< >
ostream& operator<<( ostream& os,
                         const track_field< pair<unsigned int, unsigned int> >& f ) {
  os << " (" << f.field_handle << ") " << f.name;
  try
  {
    pair<unsigned, unsigned> d = f();
    os << "( " << d.first << ", " << d.second << ") ";
  }
  catch (runtime_error const& )
  {
    os << " (no row set)";
  }
  return os;
}

template< >
ostream& operator<<( ostream& os,
                         const track_field< descriptor_cutic_type >& f) {
  os << " (" << f.field_handle << ") " << f.name;
    try
  {
    descriptor_cutic_type d = f();

    //os << "[score_class=" << d.score_class << "] ";
    //os << "[score_type=" << d.score_type << "] ";
    //os << "[sim_temporal=" << d.sim_temporal.size()  << "] ";
    //os << "[desc_index=" << d.desc_index.size() << "] ";
    os << "[desc_raw size=" << d.desc_raw.size() << "] ";

    for (size_t i=0; i<d.desc_raw.size(); ++i)
    {
      os << d.desc_raw[i] << " ";
    }

  }
  catch (runtime_error const& )
  {
    os << " (no row set)";
  }
  return os;
}


template< >
ostream& operator<<( ostream& os,
                         const track_field< descriptor_metadata_type >& f ) {
  os << " (" << f.field_handle << ") " << f.name;
  try
  {
    descriptor_metadata_type d = f();
    os << "[gsd=" << d.gsd << "] ";
    os << "[sensor_latitude=" << d.sensor_latitude << "] ";
    os << "[sensor_longitude=" << d.sensor_longitude  << "] ";
    os << "[upper_left_corner_latitude=" << d.upper_left_corner_latitude << "] ";
    os << "[upper_left_corner_longitude=" << d.upper_left_corner_longitude << "] ";
    os << "[upper_right_corner_latitude=" << d.upper_right_corner_latitude << "] ";
    os << "[upper_right_corner_longitude=" << d.upper_right_corner_longitude << "] ";
    os << "[lower_left_corner_latitude=" << d.lower_left_corner_latitude << "] ";
    os << "[lower_left_corner_longitude=" << d.lower_left_corner_longitude << "] ";
    os << "[lower_right_corner_latitude=" << d.lower_right_corner_latitude << "] ";
    os << "[lower_right_corner_longitude=" << d.lower_right_corner_longitude << "] ";
    os << "[horizontal_field_of_view=" << d.horizontal_field_of_view << "] ";
    os << "[vertical_field_of_view=" << d.vertical_field_of_view << "] ";
    os << "[timestamp_microseconds_since_1970=" << d.timestamp_microseconds_since_1970 << "] ";
    os << "[slant_range=" << d.slant_range << "] ";
  }
  catch (runtime_error const& )
  {
    os << " (no row set)";
  }
  return os;
}


template< >
ostream& operator<<( ostream& os,
                         const track_field< descriptor_motion_type >& f ) {
  os << " (" << f.field_handle << ") " << f.name;
  try
  {
    descriptor_motion_type d = f();
    os << "[ground_pos_x=" << d.ground_pos_x << "] ";
    os << "[ground_pos_y=" << d.ground_pos_y << "] ";
    os << "[ground_speed=" << d.ground_speed << "] ";
    os << "[ground_acceleration=" << d.ground_acceleration << "] ";
    os << "[heading" << d.heading << "] ";
    os << "[delta_heading=" << d.delta_heading << "] ";
    os << "[exp_heading=" << d.exp_heading << "] ";
    os << "[ang_momentum=" << d.ang_momentum << "] ";
    os << "[curvature=" << d.curvature << "] ";
  }
  catch (runtime_error const& )
  {
    os << " (no row set)";
  }
  return os;
}

template<>
ostream& operator<<( ostream& os,
                         const track_field< descriptor_overlap_type >& f ) {
  os << " (" << f.field_handle << ") " << f.name;
  try
  {
    descriptor_overlap_type d = f();
    os << d;
  }
  catch (runtime_error const& )
  {
    os << " (no row set) ";
  }
  return os;
}

template<>
ostream& operator<<( ostream& os,
                         const track_field< descriptor_event_label_type >& f ) {
  os << " (" << f.field_handle << ") " << f.name;
  try
  {
    descriptor_event_label_type d = f();
    os << d;
  }
  catch (runtime_error const& )
  {
    os << " (no row set) ";
  }
  return os;
}

template<>
ostream& operator<<( ostream& os,
                         const track_field< descriptor_raw_1d_type >& f ) {
  os << " (" << f.field_handle << ") " << f.name;
  try
  {
    descriptor_raw_1d_type d = f();
    os << d;
  }
  catch (runtime_error const& )
  {
    os << " (no row set) ";
  }
  return os;
}


template< >
ostream& operator<<( ostream& os,
                         const track_field< vector< double> >& f ) {
  os << " (" << f.field_handle << ") " << f.name;
  try
  {
    vector<double> d = f();

    os << "[size=" << d.size() << "] ";
    for (unsigned i=0; i<d.size(); ++i)
    {
      os << d[i] << " ";
    }

  }
  catch (runtime_error const& )
  {
    os << " (no row set)";
  }
  return os;
}

template< >
ostream& operator<<( ostream& os,
                         const track_field< vector< vector<double> > >& f) {
  os << " (" << f.field_handle << ") " << f.name;
  try
  {
    vector< vector< double > > d = f();
    os << "[size = " << d.size() << "]\n";
    for (unsigned i=0; i<d.size(); ++i)
    {
      vector< double > row = d[i];
      os << "  " << i << " [ size = " << row.size() << "] \n    ";
      for (unsigned j=0; j<row.size(); ++j)
      {
        os << row[j] << " ";
      }
      os << "\n";
    }
  }
  catch (runtime_error const& )
  {
    os << " (no row set)";
  }
  return os;
}

template< >
ostream& operator<<( ostream& os,
                         const track_field< vector< string> >& f )
{
  os << " (" << f.field_handle << ") " << f.name;
  try
  {
    vector<string> d = f();
    os << "[size=" << d.size() << "] ";
    for (unsigned i=0; i<d.size(); ++i)
    {
      os << d[i] << " ";
    }
  }
  catch (runtime_error const& )
  {
    os << " (no row set)";
  }
  return os;
}

template< >
ostream& operator<<( ostream& os,
                         const track_field< set< string> >& f )
{
  os << " (" << f.field_handle << ") " << f.name;
  try
  {
    set<string> d = f();
    os << "[size=" << d.size() << "] ";
    set<string>::const_iterator iter, end = d.end();
    for (iter = d.begin(); iter != end; ++iter)
    {
      os << *iter << " ";
    }
  }
  catch (runtime_error const& )
  {
    os << " (no row set)";
  }
  return os;
}

} // ...kwant
} // ...kwiver

