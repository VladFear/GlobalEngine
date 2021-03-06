#include <iostream>

#include <gtest/gtest.h>

#include "graphics/OpenGL/GLRenderSystem.h"

// Useful sites to check creation of transform matrix:
//   1) http://angrytools.com/css-generator/transform/
//   2) http://ds-overdesign.com/transform/matrix3d.html
//   3) https://ru.onlinemschool.com/math/assistance/matrix/transpose/
//
// DO NOT FORGET TO TRANSPOSE IT BEFORE CHECK.

using vec3 = glm::vec3;
using vec4 = glm::vec4;
using mat4 = glm::mat4;

TEST(createModelMatrix, Translation)
{
	GE::GLRenderSystem renderSystem;

	mat4 validationMatrix;
	validationMatrix[0] = vec4(1.0f, 0.0f, 0.0f, 0.0f);
	validationMatrix[1] = vec4(0.0f, 1.0f, 0.0f, 0.0f);
	validationMatrix[2] = vec4(0.0f, 0.0f, 1.0f, 0.0f);
	validationMatrix[3] = vec4(3.0f, 5.0f, 6.0f, 1.0f);

	mat4 modelMatrix =
		renderSystem.createModelMatrix(vec3(3.0f, 5.0f, 6.0f),
		                               vec3(0.0f),
		                               vec3(1.0f));

	ASSERT_EQ(modelMatrix, validationMatrix);
}

TEST(createModelMatrix, Scaling)
{
	GE::GLRenderSystem renderSystem;

	mat4 validationMatrix;
	validationMatrix[0] = vec4(2.0f, 0.0f, 0.0f, 0.0f);
	validationMatrix[1] = vec4(0.0f, 3.0f, 0.0f, 0.0f);
	validationMatrix[2] = vec4(0.0f, 0.0f, 4.0f, 0.0f);
	validationMatrix[3] = vec4(0.0f, 0.0f, 0.0f, 1.0f);

	mat4 modelMatrix =
		renderSystem.createModelMatrix(vec3(0.0f),
		                               vec3(0.0f),
		                               vec3(2.0f, 3.0f, 4.0f));

	ASSERT_EQ(modelMatrix, validationMatrix);
}

TEST(createModelMatrix, TraslationAndScaling)
{
	GE::GLRenderSystem renderSystem;

	mat4 validationMatrix;
	validationMatrix[0] = vec4(2.0f, 0.0f, 0.0f, 0.0f);
	validationMatrix[1] = vec4(0.0f, 3.0f, 0.0f, 0.0f);
	validationMatrix[2] = vec4(0.0f, 0.0f, 4.0f, 0.0f);
	validationMatrix[3] = vec4(1.0f, 2.0f, 3.0f, 1.0f);

	mat4 modelMatrix =
		renderSystem.createModelMatrix(vec3(1.0f, 2.0f, 3.0f),
		                               vec3(0.0f),
		                               vec3(2.0f, 3.0f, 4.0f));

	ASSERT_EQ(modelMatrix, validationMatrix);
}

// TODO: To add rotation testcase
//TEST(createTransformationMatrix, Rotation)
//{
//	glm::mat4 validation_matrix;
//	validation_matrix[0] = glm::vec4(0.0f, -1.0f, -0.75f, 0.0f);
//	validation_matrix[1] = glm::vec4(1.0f, 0.0f, -0.5f, 0.0f);
//	validation_matrix[2] = glm::vec4(0.77f, 0.05f, 0.5568f, 0.0f);
//	validation_matrix[3] = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
//
//
//	glm::mat4 transform_matrix = createTransformationMatrix(glm::vec3(0.0f),
//	                                                        glm::vec3(30.0f, 50.0f, 270.0f),
//	                                                        glm::vec3(1.0f));
//
//
//	ASSERT_EQ(transform_matrix, validation_matrix);
//}

int main(int argc, char ** argv)
{
	testing::InitGoogleTest(&argc, argv);

	return RUN_ALL_TESTS();
}
