/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2008, Willow Garage, Inc.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of the Willow Garage nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/
#ifndef TRAJECTORY_ROLLOUT_TRAJECTORY_H_
#define TRAJECTORY_ROLLOUT_TRAJECTORY_H_

#include <vector>

namespace base_local_planner {
  /**
   * @class Trajectory
   * @brief Holds a trajectory generated by considering an x, y, and theta velocity
   */
  class Trajectory {
    public:
      /**
       * @brief  Default constructor
       */
      Trajectory();

      /**
       * @brief  Constructs a trajectory
       * @param xv The x velocity used to seed the trajectory
       * @param yv The y velocity used to seed the trajectory
       * @param thetav The theta velocity used to seed the trajectory
       * @param num_pts The expected number of points for a trajectory
       */
      Trajectory(double xv, double yv, double thetav, double time_delta, unsigned int num_pts);

      double xv_, yv_, thetav_; ///< @brief The x, y, and theta velocities of the trajectory

      double cost_; ///< @brief The cost/score of the trajectory

      double time_delta_; ///< @brief The time gap between points

      /**
       * @brief  Get a point within the trajectory
       * @param index The index of the point to get
       * @param x Will be set to the x position of the point
       * @param y Will be set to the y position of the point
       * @param th Will be set to the theta position of the point
       */
      void getPoint(unsigned int index, double& x, double& y, double& th) const;

      /**
       * @brief  Set a point within the trajectory
       * @param index The index of the point to set
       * @param x The x position
       * @param y The y position
       * @param th The theta position
       */
      void setPoint(unsigned int index, double x, double y, double th);

      /**
       * @brief  Add a point to the end of a trajectory
       * @param x The x position
       * @param y The y position
       * @param th The theta position
       */
      void addPoint(double x, double y, double th);

      /**
       * @brief  Get the last point of the trajectory
       * @param x Will be set to the x position of the point
       * @param y Will be set to the y position of the point
       * @param th Will be set to the theta position of the point
       */
      void getEndpoint(double& x, double& y, double& th) const;

      /**
       * @brief  Clear the trajectory's points
       */
      void resetPoints();

      /**
       * @brief  Return the number of points in the trajectory
       * @return The number of points in the trajectory
       */
      unsigned int getPointsSize() const;

    private:
      // 轨迹点数据，x,y,theta 
      std::vector<double> x_pts_; ///< @brief The x points in the trajectory
      std::vector<double> y_pts_; ///< @brief The y points in the trajectory
      std::vector<double> th_pts_; ///< @brief The theta points in the trajectory

  };
};
#endif
